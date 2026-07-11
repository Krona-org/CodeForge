#pragma once

#include <QScrollArea>
#include <QPropertyAnimation>

class QWheelEvent;

class SmoothScrollArea : public QScrollArea
{
    Q_OBJECT

public:
    explicit SmoothScrollArea(QWidget *parent = nullptr);

protected:
    void wheelEvent(QWheelEvent *event) override;

private:
    QPropertyAnimation *m_animation;
    int m_targetValue = 0;
};