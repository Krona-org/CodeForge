#include "core/quizcontroller.hpp"

#include <algorithm>

QuizController::QuizController(PageFactory factory)
    : m_factory(std::move(factory))
{
    loadQuestions();
}

void QuizController::loadQuestions()
{
    m_questions.clear();
    const size_t pages = m_factory.totalPages();
    for (size_t i = 0; i < pages; ++i)
    {
        Page page = m_factory.createPage(static_cast<int>(i));
        for (auto &q : page.questions)
            m_questions.push_back(q);
    }
}

const Question &QuizController::current() const
{
    return m_questions.at(static_cast<size_t>(m_index));
}

QuestionLayout QuizController::currentLayout() const
{
    const Question &q = current();

    if (!q.getCodeSnippet().isEmpty())
        return QuestionLayout::SingleChoiceCode;

    const int correctCount = static_cast<int>(std::count_if(
        q.getAnswers().begin(), q.getAnswers().end(),
        [](const Option &o) { return o.isCorrect; }));

    return correctCount > 1 ? QuestionLayout::MultiChoice : QuestionLayout::SingleChoiceText;
}

bool QuizController::hasNext() const
{
    return m_index + 1 < totalCount();
}

bool QuizController::hasPrevious() const
{
    return m_index > 0;
}

void QuizController::next()
{
    if (hasNext())
    {
        ++m_index;
        clearSelection();
    }
}

void QuizController::previous()
{
    if (hasPrevious())
    {
        --m_index;
        clearSelection();
    }
}

void QuizController::skip()
{
    next();
}

void QuizController::selectSingle(int optionIndex)
{
    m_selected = { optionIndex };
}

void QuizController::toggleMulti(int optionIndex)
{
    auto it = std::find(m_selected.begin(), m_selected.end(), optionIndex);
    if (it != m_selected.end())
        m_selected.erase(it);
    else
        m_selected.push_back(optionIndex);
}

void QuizController::clearSelection()
{
    m_selected.clear();
}

bool QuizController::isCorrect() const
{
    const auto &answers = current().getAnswers();

    std::vector<int> correctIndices;
    for (int i = 0; i < static_cast<int>(answers.size()); ++i)
        if (answers[static_cast<size_t>(i)].isCorrect)
            correctIndices.push_back(i);

    if (m_selected.size() != correctIndices.size())
        return false;

    std::vector<int> selectedSorted = m_selected;
    std::sort(selectedSorted.begin(), selectedSorted.end());
    std::sort(correctIndices.begin(), correctIndices.end());

    return selectedSorted == correctIndices;
}