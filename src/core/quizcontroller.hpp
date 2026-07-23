#pragma once

#include "pagefactory.hpp"
#include "question.hpp"

#include <vector>

// Тип разметки для текущего вопроса — на какую страницу stackedWidget переключаться
enum class QuestionLayout
{
    SingleChoiceCode, // есть codeSnippet, один верный вариант
    SingleChoiceText,  // нет кода, один верный вариант
    MultiChoice        // несколько верных вариантов
};

class QuizController
{
public:


private:
    void loadQuestions();

    PageFactory m_factory;
    std::vector<Question> m_questions; // все вопросы всех страниц PageFactory, по порядку
    int m_index = 0;
    std::vector<int> m_selected; // выбранные индексы вариантов текущего вопроса
};