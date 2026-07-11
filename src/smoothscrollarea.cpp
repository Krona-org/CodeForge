#include "smoothscrollarea.h"

#include <QScrollBar>
#include <QWheelEvent>

SmoothScrollArea::SmoothScrollArea(QWidget *parent)
    : QScrollArea(parent)
{
    m_animation = new QPropertyAnimation(this);
    m_animation->setTargetObject(verticalScrollBar());
    m_animation->setPropertyName("value");
    m_animation->setEasingCurve(QEasingCurve::OutCubic);
}

void SmoothScrollArea::wheelEvent(QWheelEvent *event)
{
    QScrollBar *bar = verticalScrollBar();

    if (m_animation->state() == QPropertyAnimation::Running) {
        m_animation->stop();
    } else {
        m_targetValue = bar->value();
    }

    int delta = event->angleDelta().y();
    int step = bar->singleStep() * 3;

    m_targetValue -= (delta > 0 ? step : -step);
    m_targetValue = qBound(bar->minimum(), m_targetValue, bar->maximum());

    m_animation->setDuration(250);
    m_animation->setStartValue(bar->value());
    m_animation->setEndValue(m_targetValue);
    m_animation->start();

    event->accept();
}