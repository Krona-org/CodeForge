#pragma once

#include "core/pagefactory.hpp"
#include "core/question.hpp"

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
    explicit QuizController(PageFactory factory);

    const Question &current() const;
    QuestionLayout currentLayout() const;

    int currentIndex() const { return m_index; }
    int totalCount() const { return static_cast<int>(m_questions.size()); }

    bool hasNext() const;
    bool hasPrevious() const;

    void next();
    void previous();
    void skip();

    // Выбор ответа пользователем для текущего вопроса
    void selectSingle(int optionIndex);   // radio button
    void toggleMulti(int optionIndex);    // checkbox
    void clearSelection();

    const std::vector<int> &selectedOptions() const { return m_selected; }
    bool isAnswered() const { return !m_selected.empty(); }
    bool isCorrect() const;

private:
    void loadQuestions();

    PageFactory m_factory;
    std::vector<Question> m_questions; // все вопросы всех страниц PageFactory, по порядку
    int m_index = 0;
    std::vector<int> m_selected; // выбранные индексы вариантов текущего вопроса
};