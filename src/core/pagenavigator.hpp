// pagenavigator.hpp
#pragma once

#include <QStackedWidget>
#include <memory>
#include <qcontainerfwd.h>
#include <qdebug.h>
#include <qiterable.h>
#include "pageFiller.hpp"
#include "fabricQuest.hpp"


// нужно вложить общее количество страниц, то есть сколько вообще их

class PageNavigator
{
public:
    explicit PageNavigator(QStackedWidget* stack, std::shared_ptr<FabricQuest> m_fabQuest, std::shared_ptr<PageFiller> m_pageFiller)
                         : m_stack(stack), m_fabricQuest(m_fabQuest), m_pageFill(m_pageFiller), totalPage(m_fabQuest->getSize()), currentPage(0) 
    {
        
        m_stack->setCurrentIndex(currentPage);
        m_pageFill->fillPage(m_fabricQuest->getQuestion(currentPage), currentPage + 1, totalPage);
    }

    void goToPage(int index)
    {
        int count = m_stack->count();
        if (index < 0 || index >= count)
            return;
        m_stack->setCurrentIndex(index);
    }

    void next() { 
        if(currentPage >= m_fabricQuest->getSize() - 1)
            return;
        ++currentPage;
        goToPage(m_fabricQuest->getCurrentVar(currentPage));
        m_pageFill->fillPage(m_fabricQuest->getQuestion(currentPage), currentPage + 1, totalPage);
    }

    void previous() {
        if(currentPage <= 0)
            return;
        --currentPage;
        goToPage(m_fabricQuest->getCurrentVar(currentPage));
        m_pageFill->fillPage(m_fabricQuest->getQuestion(currentPage), currentPage + 1, totalPage);
    }

    void getCount()
    {
        qDebug() << "Количество страниц " << m_stack->count();
    }

private:
    QStackedWidget* m_stack;
    std::shared_ptr<FabricQuest> m_fabricQuest;
    std::shared_ptr<PageFiller> m_pageFill;
    //QIterator<QVector<>>
    int currentPage;
    int totalPage;
};