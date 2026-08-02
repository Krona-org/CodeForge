// сейчас не используется
#pragma once

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QPalette>

class BackgroundManager
{
public:
    explicit BackgroundManager(QWidget *target) : m_target(target) {}
    void setImage(const QString &path);
    void update();

private:
    QWidget *m_target;
    QPixmap m_originalPixmap;
};

inline void BackgroundManager::setImage(const QString &path)
{
    m_originalPixmap = QPixmap(path);
    update();
}

inline void BackgroundManager::update()
{
    if (m_originalPixmap.isNull())
        return; 

    QPixmap pm = m_originalPixmap.scaled(m_target->size(),
                                            Qt::IgnoreAspectRatio,
                                            Qt::SmoothTransformation);
    QPainter painter(&pm);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.fillRect(pm.rect(), QColor(0, 0, 0, 150));
    painter.end();

    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(pm));
    m_target->setPalette(palette);
    m_target->setAutoFillBackground(true);
}