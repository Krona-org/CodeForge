#pragma once
#include <qmainwindow.h>
#include <qtconfigmacros.h>
#include <qtmetamacros.h>
#include "pagenavigator.hpp"
#include "core/quizcontroller.hpp"

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

    QuizController *m_quiz = nullptr;

    void showCurrentQuestion();

    Ui::MainWindow *ui;
    PageNavigator *m_navigator;
    // QuizController *m_quiz;

    void buildQuestionNav(int questionCount);

private slots:    
    void on_pushButton_1_clicked(); // "Назад" page 1
    void on_pushButton_2_clicked(); // "Ответить" page 1
    void on_pushButton_3_clicked(); // "Пропустить" page 1

    void on_pushButton_4_clicked(); // "Назад" page 2
    void on_pushButton_5_clicked(); // "Ответить" page 2
    void on_pushButton_6_clicked(); // "Пропустить" page 2

    void on_pushButton_7_clicked(); // "Назад" page 3
    void on_pushButton_8_clicked(); // "Ответить" page 3
    void on_pushButton_9_clicked(); // "Пропустить" page 3
};