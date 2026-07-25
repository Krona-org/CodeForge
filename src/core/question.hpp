// core/question.hpp
#pragma once

#include <QString>
#include <QVector>
#include <atomic>

struct AnswerOption 
{
    QString text;
    bool isCorrect = false;
};
class Question 
{
public:
    Question() : globalId(countGlobalId()) {};
    virtual ~Question() {};
    int getGlobalId() const { return this->globalId; }

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
    CountedQuestion() : privateId(countPrivateId()) {};
    int getPrivateId() const { return privateId; }
    
private:
    int countPrivateId();
private:
    int privateId;
};

class oneVarQuestion : public CountedQuestion<oneVarQuestion> {};
class twoVarQuestion : public CountedQuestion<twoVarQuestion> {};
class threeVarQuestion : public CountedQuestion<threeVarQuestion> {};


inline int Question::countGlobalId() 
{
    static std::atomic<int> temp = 0;
    return temp++;
}

template<typename Derived>
inline int CountedQuestion<Derived>::countPrivateId() 
{
    static std::atomic<int> temp = 0;
    return temp++;
}