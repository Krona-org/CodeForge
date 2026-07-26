#include <qmainwindow.h>
#include <qobject.h>
#include <qpixmap.h>
#include <qpainter.h>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QAbstractButton>
#include <QStyle>

#include <qscrollbar.h>

#include "ui_mainwindow.h"
#include "mainwindow.h"

#include "questTest.hpp"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_navigator = new PageNavigator(ui->stackedWidget);

    initializeFullPage();          // хардкодим вопросы в m_factory
    ui->bodySolution_page1->setText(m_fabricQuest.getQuestion(0, 0)->getBodySolution());
}

MainWindow::~MainWindow() { delete ui;} 

void MainWindow::on_pushButton_1_clicked() { }
void MainWindow::on_pushButton_2_clicked() {  }
void MainWindow::on_pushButton_3_clicked() {  }
void MainWindow::on_pushButton_4_clicked() {  }
void MainWindow::on_pushButton_5_clicked() { }
void MainWindow::on_pushButton_6_clicked() { }
void MainWindow::on_pushButton_7_clicked() {}
void MainWindow::on_pushButton_8_clicked() {}
void MainWindow::on_pushButton_9_clicked() {}
