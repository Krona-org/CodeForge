#pragma once

#include <functional>
#include <map>
#include <memory>
#include <qcontainerfwd.h>
#include "question.hpp"

// переписываем заново 

class FabricQuest final
{
public:
    FabricQuest() = default;
    void push_back(int indexPage, QString BodyTitle,
                    QString BrowCode, QString BodyCode,
                    QString BrowSolution, QString BodySolution,
                    QVector<AnswerOption> Answer);

    int getSize();
    std::shared_ptr<Question> getQuestion(int indexPage) const;

private:
    QVector<std::shared_ptr<Question>> v_question;
};

inline int FabricQuest::getSize() { return v_question.size(); }
inline void FabricQuest::push_back(int indexPage, QString BodyTitle,
                    QString BrowCode, QString BodyCode,
                    QString BrowSolution, QString BodySolution,
                    QVector<AnswerOption> Answer)
{
    v_question.push_back(std::make_shared<Question>(indexPage, BodyTitle, BrowCode,
                                                    BodyCode, BrowSolution, BodySolution, Answer));
}
inline std::shared_ptr<Question> FabricQuest::getQuestion(int indexPage) const
{
    return v_question.at(indexPage);
}