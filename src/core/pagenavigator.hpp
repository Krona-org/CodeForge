// pagenavigator.hpp
#pragma once

#include <QStackedWidget>
#include <vector>
#include <qdebug.h>

class PageNavigator
{
public:
    explicit PageNavigator(QStackedWidget *stack) : m_stack(stack) {}

    void goToPage(int index)
    {
        int count = m_stack->count();
        if (index < 0 || index >= count)
            return;
        m_stack->setCurrentIndex(index);
    }

    void next() { goToPage(m_stack->currentIndex() + 1); }
    void previous() { goToPage(m_stack->currentIndex() - 1); }

    void getCount()
    {
        qDebug() << "Количество страниц " << m_stack->count();
    }

private:
    QStackedWidget *m_stack;
    std::vector<int> questionPage;
};