#pragma once
#include <qmainwindow.h>
#include <qtconfigmacros.h>
#include <qtmetamacros.h>

#include "pagenavigator.hpp"
#include "fabricQuest.hpp"
#include "pageFiller.hpp"

QT_BEGIN_NAMESPACE
namespace Ui{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parrent = nullptr);
    ~MainWindow();
    void setBackgroundImage(const QString &path);

protected:

private:
    void updateBackground();
    void goToPage(int index);

    Ui::MainWindow *ui;
    PageNavigator *m_navigator;
    FabricQuest* m_fabricQuest;
    PageFiller* m_pageFiiler;
    int count;
    void initializeFullPage(); // хардкод всех вопросов (временно, пока нет реальных данных)

    void buildQuestionNav(int questionCount);

private slots:    
    void on_backButton_page1_clicked(); // "назад" page 1
    void on_nextButton_page1_clicked(); // "ответить" page 1
    void on_skipButton_page1_clicked(); // "Пропустить" page 1

    void on_backButton_page2_clicked(); //
    void on_nextButton_page2_clicked(); //
    void on_skipButton_page2_clicked(); //

    void on_backButton_page3_clicked(); //
    void on_nextButton_page3_clicked(); //
    void on_skipButton_page3_clicked(); //

};