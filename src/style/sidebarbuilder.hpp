// sidebarbuilder.hpp
#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStringList>
#include <QDebug>
#include "stypehelper.hpp"

class SideBarBuilder
{
public:
    static void build(QWidget *container, QVBoxLayout *layout, const QStringList &items)
    {
        for (const QString &text : items) {
            QPushButton *btn = new QPushButton(text, container);
            btn->setMinimumHeight(40);
            btn->setStyleSheet(StyleHelper::getStyleBtnSlideBar());
            layout->addWidget(btn);

            QObject::connect(btn, &QPushButton::clicked, container, [text]() {
                qDebug() << "Нажата кнопка:" << text;
            });
        }
        layout->addStretch();
    }
};