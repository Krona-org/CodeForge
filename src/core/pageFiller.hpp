#pragma once


#include "question.hpp"
#include "ui_mainwindow.h"
#include "cppsyntaxhighlighter.hpp"
#include "codesize.hpp"
#include <memory>


class PageFiller
{
public:
    PageFiller(Ui::MainWindow* ui) : ui(ui) {
        highlighter_page1 = std::make_shared<CppSyntaxHighlighter>(ui->bodyCode_page1->document());
    };
    void fillPage_1(std::shared_ptr<Question> Quest, const int& current, const int& total);
    void fillPage_2(std::shared_ptr<Question> Quest);
    void fillPage_3(std::shared_ptr<Question> Quest);
private:
    Ui::MainWindow* ui;
    std::shared_ptr<CppSyntaxHighlighter> highlighter_page1 = nullptr;

};
inline void PageFiller::fillPage_1(std::shared_ptr<Question> Quest, const int& current, const int& total)
{
    ui->browTitle_page1->setText(QString("Вопрос %1 из %2").arg(current).arg(total));
    ui->bodyTitle_page1->setText(Quest->getBodyTitle());
    ui->browCode_page1->setText(Quest->getBrowCode());
    ui->bodyCode_page1->setPlainText(Quest->getBodyCode());
    ui->browSolution_page1->setText(Quest->getBrowSolution());
    ui->bodySolution_page1->setText(Quest->getBodySolution());
    // ui->answerButton1_page1
    // ui->answerButton2_page1
    // ui->answerButton3_page1
    // ui->answerButton4_page1
    CodeSize::fitCodeEditHeight(ui->bodyCode_page1);   // <-- добавить

}
inline void PageFiller::fillPage_2(std::shared_ptr<Question> Quest)
{
    // ui->bodyTitle_page2->setText(Quest->getBodyTitle());
    // ui->browCode_page2->setText(Quest->getBrowCode());
    // ui->bodyCode_page2->setPlainText(Quest->getBodyCode());
    // ui->browSolution_page2->setText(Quest->getBrowSolution());
    // ui->bodySolution_page2->setText(Quest->getBodySolution());
    // ui->
    // ui->answerButton1_page1
    // ui->answerButton2_page1
    // ui->answerButton3_page1
    // ui->answerButton4_page1
}
// как должен работать логика заполнения страницы
// 1. через фабрику создается вопрос для шаблона вопроса по индексу
// 2. в зависимости от индекса шаблона и номера страницы текст копируется в Ui
// 3. переключения между страницыми происходит используя кнопки навигации