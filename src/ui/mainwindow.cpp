#include <QMainWindow>
#include <QWidget>

#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "questTest.hpp"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pageFiiler = new PageFiller(ui);
    m_fabricQuest = new FabricQuest();
    initializeFullPage();          // хардкодим вопросы в m_factory
    m_navigator = new PageNavigator(ui->stackedWidget, m_fabricQuest, m_pageFiiler, m_fabricQuest->totalPage());
}

MainWindow::~MainWindow() { delete ui;} 

    void MainWindow::on_backButton_page1_clicked() 
    {
         m_navigator->previous(); 
    } 
    void MainWindow::on_nextButton_page1_clicked() 
    {
         m_navigator->next(); 
    } 
    void MainWindow::on_skipButton_page1_clicked() { m_navigator->next(); } 

    void MainWindow::on_backButton_page2_clicked() { m_navigator->previous(); } 
    void MainWindow::on_nextButton_page2_clicked() { m_navigator->next(); } 
    void MainWindow::on_skipButton_page2_clicked() { m_navigator->next(); } 

    void MainWindow::on_backButton_page3_clicked() { m_navigator->previous(); } 
    void MainWindow::on_nextButton_page3_clicked() { m_navigator->next(); } 
    void MainWindow::on_skipButton_page3_clicked() { m_navigator->next(); } 
