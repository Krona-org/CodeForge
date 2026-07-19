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
    ui->questionEyebrowLabel->setText(QString::fromStdString(std::format("Попрос {0} из {1}", a, size)));


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

