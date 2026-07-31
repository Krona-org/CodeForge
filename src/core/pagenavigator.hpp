// pagenavigator.hpp
#pragma once

#include <QStackedWidget>
#include <memory>
#include <qdebug.h>
#include "pageFiller.hpp"
#include "fabricQuest.hpp"


// нужно вложить общее количество страниц, то есть сколько вообще их

class PageNavigator
{
public:
    explicit PageNavigator(QStackedWidget* stack, std::shared_ptr<FabricQuest> m_fabQuest, std::shared_ptr<PageFiller> m_pageFiller , int totalPage)
                         : m_stack(stack), m_fabricQuest(m_fabQuest), m_pageFill(m_pageFiller), totalPage(totalPage), currentPage(0) 
    {
        
        m_stack->setCurrentIndex(currentPage);
        m_pageFill->fillPage_1(m_fabricQuest->getQuestion(0, currentPage), currentPage + 1, totalPage);
    }

    void goToPage(int index)
    {
        int count = m_stack->count();
        if (index < 0 || index >= count)
            return;
        m_stack->setCurrentIndex(index);
    }

    void next() { 
        if(currentPage >= m_fabricQuest->getSizeQuestion(0) - 1)
            return;
        ++currentPage;
        m_pageFill->fillPage_1(m_fabricQuest->getQuestion(0, currentPage), currentPage + 1, totalPage);
    }

    void previous() {
        if(currentPage <= 0)
            return;
        --currentPage;
        m_pageFill->fillPage_1(m_fabricQuest->getQuestion(0, currentPage), currentPage + 1, totalPage);
    }

    void getCount()
    {
        qDebug() << "Количество страниц " << m_stack->count();
    }

private:
    QStackedWidget* m_stack;
    std::shared_ptr<FabricQuest> m_fabricQuest;
    std::shared_ptr<PageFiller> m_pageFill;
    int currentPage;
    int totalPage;
};