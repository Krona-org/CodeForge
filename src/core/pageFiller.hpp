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
    void fillPage(std::shared_ptr<Question> Quest, const int& current, const int& total);
private:
    Ui::MainWindow* ui;
    std::shared_ptr<CppSyntaxHighlighter> highlighter_page1 = nullptr;
    void fillPage_1(std::shared_ptr<Question> Quest, const int& current, const int& total);
    void fillPage_2(std::shared_ptr<Question> Quest, const int& current, const int& total);
    void fillPage_3(std::shared_ptr<Question> Quest, const int& current, const int& total);

};

inline void PageFiller::fillPage(std::shared_ptr<Question> Quest, const int& current, const int& total)
{
    if (Quest->getVarIndex() == 0)
        fillPage_1(Quest, current, total);
    else if (Quest->getVarIndex() == 1)
        fillPage_2(Quest, current, total);
    else if (Quest->getVarIndex() == 2)
        fillPage_3(Quest, current, total);
    ui->scrollArea->verticalScrollBar()->setValue(0); // вернуть курсор на начало страницы
}

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
inline void PageFiller::fillPage_2(std::shared_ptr<Question> Quest, const int& current, const int& total)
{
    ui->browTitle_page2->setText(QString("Вопрос %1 из %2").arg(current).arg(total));
    ui->bodyTitle_page2->setText(Quest->getBodyTitle());
    // ui->browCode_page2->setText(Quest->getBrowCode());
    // ui->bodyCode_page2->setPlainText(Quest->getBodyCode());
    ui->browSolution_page2->setText(Quest->getBrowSolution());
    ui->bodySolution_page2->setText(Quest->getBodySolution());
    // ui->answerButton1_page1
    // ui->answerButton2_page1
    // ui->answerButton3_page1
    // ui->answerButton4_page1
}
inline void PageFiller::fillPage_3(std::shared_ptr<Question> Quest, const int& current, const int& total)
{
    ui->browTitle_page3->setText(QString("Вопрос %1 из %2").arg(current).arg(total));
    ui->bodyTitle_page3->setText(Quest->getBodyTitle());
    // ui->browCode_page2->setText(Quest->getBrowCode());
    // ui->bodyCode_page2->setPlainText(Quest->getBodyCode());
    ui->browSolution_page3->setText(Quest->getBrowSolution());
    ui->bodySolution_page3->setText(Quest->getBodySolution());
    // ui->answerButton1_page1
    // ui->answerButton2_page1
    // ui->answerButton3_page1
    // ui->answerButton4_page1
}