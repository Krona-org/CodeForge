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
    Question(QString BodyTitle, QString BrowCode, QString BodyCode,
                QString BrowSolution, QString BodySolution, QVector<AnswerOption> Answer);
    virtual ~Question() = default;
    virtual int getPrivateId() const = 0;
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
    int globalId;
    QString browTitle;
    QString bodyTitle;
    QString browCode;
    QString bodyCode;
    QString browSolution;
    QString bodySolution;
    QVector<AnswerOption> answer;
};

template<typename Derived>
class CountedQuestion : public Question
{
public:
    CountedQuestion(QString BodyTitle, QString BrowCode, QString BodyCode,
                     QString BrowSolution, QString BodySolution, QVector<AnswerOption> Answer)
            :Question(BodyTitle,  BrowCode,  BodyCode, BrowSolution,  BodySolution, Answer),
                       privateId(countPrivateId()) {}
    int getPrivateId() const override { return privateId; }
    
private:
    int countPrivateId() ;
private:
    int privateId;
};

class oneVarQuestion : public CountedQuestion<oneVarQuestion> {
public:
    using CountedQuestion<oneVarQuestion>::CountedQuestion; // наследую конструктор базового класса
};
class twoVarQuestion : public CountedQuestion<twoVarQuestion> {
public:
    using CountedQuestion<twoVarQuestion>::CountedQuestion;
};
class threeVarQuestion : public CountedQuestion<threeVarQuestion> {
public:
    using CountedQuestion<threeVarQuestion>::CountedQuestion;
};

inline Question::Question(QString BodyTitle, QString BrowCode, QString BodyCode,
                            QString BrowSolution, QString BodySolution, QVector<AnswerOption> Answer)
{
    globalId = countGlobalId();
    this->bodyTitle = BodyTitle;
    this->browCode = BrowCode;
    this->bodyCode = BodyCode;
    this->browSolution = BrowSolution;
    this->bodySolution = BodySolution;
    this->answer = Answer;
}

inline int Question::countGlobalId() 
{
    static std::atomic<int> temp = 0;
    return temp++;
}

inline int Question::getGlobalId()         { return globalId; }
inline QString Question::getBrowTitle()    { return browTitle; }
inline QString Question::getBodyTitle()    { return bodyTitle; }
inline QString Question::getBrowCode()     { return browCode; }
inline QString Question::getBodyCode()     { return bodyCode; }
inline QString Question::getBrowSolution() { return browSolution; }
inline QString Question::getBodySolution() { return bodySolution; }
inline const QVector<AnswerOption>& Question::getAnswer() const { return answer; } 


template<typename Derived>
inline int CountedQuestion<Derived>::countPrivateId() 
{
    static std::atomic<int> temp = 0;
    return temp++;
}

