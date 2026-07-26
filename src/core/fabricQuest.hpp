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
    FabricQuest();
    void push_back(int indexPage, QString BodyTitle,
                    QString BrowCode, QString BodyCode,
                    QString BrowSolution, QString BodySolution,
                    QVector<AnswerOption> Answer);
    std::shared_ptr<Question> getQuestion(int indexPage, int num) const;

private:
    template<typename T>
    void registerType(int indexPage);

    std::map<int, std::vector<std::shared_ptr<Question>>> mapQuest;
    std::map<int, std::function<std::shared_ptr<Question>(QString, QString,
                                                            QString, QString,
                                                            QString, QVector<AnswerOption>)>> creators;
};

template<typename T>
inline void FabricQuest::registerType(int indexPage)
{
    creators[indexPage] = [](QString BodyTitle, QString BrowCode, QString BodyCode,
                                  QString BrowSolution, QString BodySolution, QVector<AnswerOption> Answer) 
    {
        return std::make_shared<T>(BodyTitle, BrowCode, BodyCode, BrowSolution, BodySolution, Answer);
    };
}
inline FabricQuest::FabricQuest()
{
    registerType<oneVarQuestion>(0);
    registerType<twoVarQuestion>(1);
    registerType<threeVarQuestion>(2);
};

inline void FabricQuest::push_back(int indexPage, QString BodyTitle,
                                    QString BrowCode, QString BodyCode,
                                    QString BrowSolution, QString BodySolution,
                                    QVector<AnswerOption> Answer)
{
    auto it = creators.find(indexPage);
    if(it == creators.end())
        throw std::invalid_argument("uncnown indexPage");

    mapQuest[indexPage].push_back(it->second(BodyTitle, BrowCode, BodyCode,
                                                BrowSolution, BodySolution, Answer));
}
inline std::shared_ptr<Question> FabricQuest::getQuestion(int indexPage, int num) const
{
    return mapQuest.at(indexPage).at(num);
}