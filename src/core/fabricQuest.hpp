#pragma once

#include <functional>
#include <map>
#include <memory>
#include <qcontainerfwd.h>
#include "question.hpp"

// переписываем заново 

class FabricQuest
{
public:
    FabricQuest() 
    {
        registerType<oneVarQuestion>(0);
        registerType<twoVarQuestion>(1);
        registerType<threeVarQuestion>(2);
    };
    void push_back(int indexPage, QString BodyTittle, QString BrowCode, QString BodyCode,
                     QString BrowSolution, QString BodySolution, QVector<AnswerOption> Answer)
    {
        auto it = creators.find(indexPage);
        if(it == creators.end())
            throw std::invalid_argument("uncnown indexPage");

        mapQuest[indexPage].push_back(it->second(BodyTittle, BrowCode, BodyCode,
                                                    BrowSolution, BodySolution, Answer));
    }
    int getIndex(int indexPage, int num) 
    { 
        return mapQuest.at(indexPage).at(num)->getPrivateId();
    }

private:
    template<typename T>
    void registerType(int indexPage)
    {
        creators[indexPage] = [](QString BodyTitle, QString BrowCode, QString BodyCode,
                                  QString BrowSolution, QString BodySolution, QVector<AnswerOption> Answer) 
        {
            return std::make_shared<T>(BodyTitle, BrowCode, BodyCode, BrowSolution, BodySolution, Answer);
        };
    }
    std::map<int, std::function<std::shared_ptr<Question>(QString, QString, QString, QString, QString, QVector<AnswerOption>)>> creators;
    std::map<int, std::vector<std::shared_ptr<Question>>> mapQuest;
};