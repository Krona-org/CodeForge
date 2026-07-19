// core/pagefactory.hpp
#pragma once

#include "question.hpp"
#include <vector>
#include <map>

// Структура, объединяющая вопросы для одной страницы
struct Page 
{
    int pageIndex;
    std::vector<Question> questions;
};

class PageFactory
{
public:
    PageFactory();

    // Главные методы для работы со страницами
    Page createPage(int index) const;
    size_t totalPages() const;

    // Метод для динамического добавления вопросов (например, при парсинге JSON)
    void addQuestionToPage(int pageIndex, const Question& question);

private:
    // Храним страницы в map, где ключ — индекс страницы
    std::map<int, std::vector<Question>> m_pagesData;

    // Внутренний метод для хардкода начальных вопросов (если базы данных пока нет)
    void loadDefaultMockData();
};

inline PageFactory::PageFactory() 
{
    loadDefaultMockData();
}

inline Page PageFactory::createPage(int index) const 
{
    Page page;
    page.pageIndex = index;

    // Ищем, есть ли у нас вопросы для этой страницы
    auto it = m_pagesData.find(index);
    if (it != m_pagesData.end()) {
        page.questions = it->second; // Копируем (или возвращаем shared_ptr, если не хотим копировать)
    }

    return page;
}

inline size_t PageFactory::totalPages() const 
{
    return m_pagesData.size();
}

inline void PageFactory::addQuestionToPage(int pageIndex, const Question& question) 
{
    m_pagesData[pageIndex].push_back(question);
}

inline void PageFactory::loadDefaultMockData() 
{
    // Страница 0
    addQuestionToPage(0, Question(
        "Что выведет этот код на C++?",
        {{"0", false}, {"1", true}, {"Ошибка компиляции", false}},
        "Статические переменные сохраняют свое значение между вызовами.",
        "ВОПРОС 1 ИЗ 2",
        "int foo() { static int x = 0; return x++; }"
    ));

    // Страница 1
    addQuestionToPage(1, Question(
        "Какая сложность поиска в std::map?",
        {{"O(1)", false}, {"O(log N)", true}, {"O(N)", false}},
        "std::map в C++ обычно реализуется как красно-черное дерево."
    ));
}