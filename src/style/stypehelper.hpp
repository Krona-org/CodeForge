#pragma once
#include <qstring.h>

class StyleHelper
{
public:
    static inline QString getMainWidgetStyle(const QString &imagePath);
    static inline QString getGlassStyle();
    static inline QString getStyleBtnSlideBar();
};


// Стиль для главного виджета
QString StyleHelper::getMainWidgetStyle(const QString &imagePath) {
    return QString(R"(
        QWidget#centralwidget {
            border-image: url(%1) 0 0 0 0 stretch stretch;
        }
    )").arg(imagePath);
}

QString StyleHelper::getGlassStyle(){
    return R"( 
        QWidget, QGroupBox {
          background-color: rgba(255, 255, 255, 20);   /* полупрозрачный белый */
          border: 1px solid rgba(255, 255, 255, 40);   /* полупрозрачная рамка */
          border-radius: 12px;                         /* скруглённые углы */
          color: white;
          margin-top: 8px;
        }
        QGroupBox::title {
          subcontrol-origin: margin;
          left: 10px;
          color: rgba(255, 255, 255, 200);
        }
    )";

}

QString StyleHelper::getStyleBtnSlideBar(){
    return R"(
        QPushButton {
            background-color: rgb(17, 23, 24);
            color: rgb(199, 212, 210);
            border: 1px solid rgb(33, 48, 50);
            border-radius: 6px;
            text-align: left;
            padding-left: 16px;
            font-family: Consolas;
            font-size: 10pt;
        }
        QPushButton:hover {
            background-color: rgb(22, 30, 32);
            border-color: rgb(51, 64, 63);
        }
        QPushButton:pressed {
            background-color: rgb(255, 140, 0);
            color: rgb(12, 16, 17);
        }
        QPushButton:checked {
            background-color: rgb(255, 140, 0);
            color: rgb(12, 16, 17);
            border-color: rgb(255, 178, 56);
        }
        )";
}