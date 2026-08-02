#pragma once

#include <memory>
#include <qcontainerfwd.h>
#include "question.hpp"


class FabricQuest final
{
public:
    FabricQuest() = default;

    int getSize();
    int getCurrentVar(const int& index);
    std::shared_ptr<Question> getQuestion(const int& indexPage);
    void push_back(int indexPage,
                   QString BodyTitle,
                   QString BrowCode,
                   QString BodyCode,
                   QString BrowSolution,
                   QString BodySolution,
                   QVector<AnswerOption> Answer);

private:
    QVector<std::shared_ptr<Question>> v_question;
};

inline int FabricQuest::getSize()                                                  { return v_question.size(); }
inline int FabricQuest::getCurrentVar(const int& index)                            { return v_question.at(index)->getVarIndex(); }
inline std::shared_ptr<Question> FabricQuest::getQuestion(const int& indexPage)    { return v_question.at(indexPage); }
inline void FabricQuest::push_back(int indexPage,
                                   QString BodyTitle,
                                   QString BrowCode,
                                   QString BodyCode,
                                   QString BrowSolution,
                                   QString BodySolution,
                                   QVector<AnswerOption> Answer)
{
    v_question.push_back(std::make_shared<Question>(indexPage,
                                                       BodyTitle,
                                                       BrowCode,
                                                       BodyCode,
                                                       BrowSolution,
                                                       BodySolution,
                                                       Answer));
}