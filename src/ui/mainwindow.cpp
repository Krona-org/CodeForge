#include <qmainwindow.h>
#include <qnamespace.h>
#include <qobject.h>
#include <qpixmap.h>
#include <qpainter.h>
#include <QWidget>
#include <QLabel>
#include <QPushButton>

#include <qscrollbar.h>

#include "ui_mainwindow.h"
#include "codesize.hpp"
#include "mainwindow.h"
#include "cppsyntaxhighlighter.hpp"
#include "stypehelper.hpp"



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->codeFileNameLabel->setText("shapes_demo.cpp");
    m_navigator = new PageNavigator(ui->stackedWidget);
    CodeSize::fitCodeEditHeight(ui->codeTextEdit);
    new CppSyntaxHighlighter(ui->codeTextEdit->document());
    int a = 1, size = 10;
    //ui->questionEyebrowLabel->setText(QString::fromStdString(std::format("Попрос {0} из {1}", a, size)));

    buildQuestionNav(6);

    // отладка вывод в консоль
    m_navigator->getCount(); //  количество страниц
}

MainWindow::~MainWindow() { delete ui;} 

void MainWindow::on_pushButton_1_clicked() { m_navigator->previous(); }
void MainWindow::on_pushButton_2_clicked() { m_navigator->next(); }
void MainWindow::on_pushButton_3_clicked() { m_navigator->next(); }
void MainWindow::on_pushButton_4_clicked() { m_navigator->previous(); }
void MainWindow::on_pushButton_5_clicked() { m_navigator->next(); }
void MainWindow::on_pushButton_6_clicked() { m_navigator->next(); }
void MainWindow::on_pushButton_7_clicked() { m_navigator->previous(); }
void MainWindow::on_pushButton_8_clicked() { m_navigator->next(); }
void MainWindow::on_pushButton_9_clicked() { m_navigator->next(); }

void MainWindow::buildQuestionNav(int questionCount)
{
    QVBoxLayout* layout = ui->verticalLayout_8;

    // чистим всё, что лежало в лэйауте
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (item->widget())
            item->widget()->deleteLater();
        delete item;
    }

    // Ваш стиль для кнопок
    QString buttonStyle = 
        "QPushButton {"
        "    font-family: \"IBM Plex Mono\";"
        "    font-weight: 500;"
        "    background-color: rgb(17, 23, 24);"
        "    color: rgb(199, 212, 210);"
        "    border: 1px solid rgb(33, 48, 50);"
        "    border-radius: 4px;"
        "    padding: 8px 16px;"
        "}"
        "QPushButton:hover {"
        "    background-color: rgb(22, 30, 32);"
        "    border-color: rgb(51, 64, 63);"
        "}";

    for (int i = 0; i < questionCount; ++i) {
        auto* btn = new QPushButton(QString("Вопрос %1").arg(i + 1), this);
        btn->setMinimumHeight(35); // Меняем на 35
        btn->setStyleSheet(buttonStyle);

        connect(btn, &QPushButton::clicked, this, [this, i]() {
            m_navigator->goToPage(i);
        });

        layout->addWidget(btn, 0, Qt::AlignTop);
    }

    layout->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
}