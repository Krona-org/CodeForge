#pragma once


#include "question.hpp"
#include "ui_mainwindow.h"
#include <memory>


class PageFiller
{
public:
    PageFiller(Ui::MainWindow* ui) : ui(ui) {};
    void fillPage_1(std::shared_ptr<Question> oneQuest);
    void fillPage_2(twoVarQuestion* twoQuestion);
    void fillPage_3(threeVarQuestion* threeQuestion);
private:
    Ui::MainWindow *ui;
};
inline void PageFiller::fillPage_1(std::shared_ptr<Question> oneQuest)
{
    ui->bodyTitle_page1->setText(oneQuest->getBodyTitle());
    ui->browCode_page1->setText(oneQuest->getBrowCode());
    ui->bodyCode_page1->setPlainText(oneQuest->getBodyCode());
    ui->browSolution_page1->setText(oneQuest->getBrowSolution());
    ui->bodySolution_page1->setText(oneQuest->getBodySolution());
    // ui->answerButton1_page1
    // ui->answerButton2_page1
    // ui->answerButton3_page1
    // ui->answerButton4_page1
}
// как должен работать логика заполнения страницы
// 1. через фабрику создается вопрос для шаблона вопроса по индексу
// 2. в зависимости от индекса шаблона и номера страницы текст копируется в Ui
// 3. переключения между страницыми происходит используя кнопки навигации