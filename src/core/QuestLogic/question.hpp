// core/question.hpp
#pragma once

#include <QString>
#include <QVector>


struct AnswerOption 
{
    QString text;
    bool isCorrect = false;
};

class Question 
{
public:
    Question(int var,
             QString BodyTitle,
             QString BrowCode,
             QString BodyCode,
             QString BrowSolution,
             QString BodySolution,
             QVector<AnswerOption> Answer);

    int getVarIndex() const;
    int getGlobalId() const;

    QString getBrowTitle() const;
    QString getBodyTitle() const;
    QString getBrowCode() const;
    QString getBodyCode() const;
    QString getBrowSolution() const;
    QString getBodySolution() const;
    const QVector<AnswerOption>& getAnswer() const;

private:
    int varQuest;
    int globalId;
    QString browTitle;
    QString bodyTitle;
    QString browCode;
    QString bodyCode;
    QString browSolution;
    QString bodySolution;
    QVector<AnswerOption> answer;
};

inline Question::Question(int var,
                          QString BodyTitle,
                          QString BrowCode,
                          QString BodyCode,
                          QString BrowSolution,
                          QString BodySolution,
                          QVector<AnswerOption> Answer)
{
    this->varQuest = var;
    this->bodyTitle = BodyTitle;
    this->browCode = BrowCode;
    this->bodyCode = BodyCode;
    this->browSolution = BrowSolution;
    this->bodySolution = BodySolution;
    this->answer = Answer;
}

inline int Question::getVarIndex() const                        { return varQuest; }
inline int Question::getGlobalId() const                        { return globalId; }
inline QString Question::getBrowTitle() const                   { return browTitle; }
inline QString Question::getBodyTitle() const                   { return bodyTitle; }
inline QString Question::getBrowCode() const                    { return browCode; }
inline QString Question::getBodyCode() const                    { return bodyCode; }
inline QString Question::getBrowSolution() const                { return browSolution; }
inline QString Question::getBodySolution() const                { return bodySolution; }
inline const QVector<AnswerOption>& Question::getAnswer() const { return answer; } 
