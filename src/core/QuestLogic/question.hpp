// core/question.hpp
#pragma once

#include <QString>
#include <QVector>
#include <atomic>
#include <qcontainerfwd.h>

struct AnswerOption 
{
    QString text;
    bool isCorrect = false;
};

class Question 
{
public:
    Question(int var, QString BodyTitle, QString BrowCode, QString BodyCode,
                QString BrowSolution, QString BodySolution, QVector<AnswerOption> Answer);
    virtual ~Question() = default;
    int getVarIndex();
    int getGlobalId();
    QString getBrowTitle();
    QString getBodyTitle();
    QString getBrowCode();
    QString getBodyCode();
    QString getBrowSolution();
    QString getBodySolution();
    const QVector<AnswerOption>& getAnswer() const;

private:
    int countGlobalId();

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

inline Question::Question(int var, QString BodyTitle, QString BrowCode, QString BodyCode,
                            QString BrowSolution, QString BodySolution, QVector<AnswerOption> Answer)
{
    this->varQuest = var;
    this->bodyTitle = BodyTitle;
    this->browCode = BrowCode;
    this->bodyCode = BodyCode;
    this->browSolution = BrowSolution;
    this->bodySolution = BodySolution;
    this->answer = Answer;
    globalId = countGlobalId();
}

inline int Question::countGlobalId() 
{
    static std::atomic<int> temp = 0;
    return temp++;
}

inline int Question::getVarIndex()         { return this->varQuest; }
inline int Question::getGlobalId()         { return globalId; }
inline QString Question::getBrowTitle()    { return browTitle; }
inline QString Question::getBodyTitle()    { return bodyTitle; }
inline QString Question::getBrowCode()     { return browCode; }
inline QString Question::getBodyCode()     { return bodyCode; }
inline QString Question::getBrowSolution() { return browSolution; }
inline QString Question::getBodySolution() { return bodySolution; }
inline const QVector<AnswerOption>& Question::getAnswer() const { return answer; } 
