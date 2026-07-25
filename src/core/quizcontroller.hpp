#pragma once

#include <functional>
#include <map>
#include "question.hpp"

// переписываем заново 

class FabricQuest
{
public:
    FabricQuest() {
        registerType<oneVarQuestion>(0);
        registerType<twoVarQuestion>(1);
        registerType<threeVarQuestion>(2);
    };
    void push_back(int indexPage)
    {
        auto it = creators.find(indexPage);
        if(it == creators.end())
            throw std::invalid_argument("uncnown indexPage");

        mapQuest[indexPage].push_back(it->second());
    }
    int getIndex(int indexPage, int num) 
    { 
        return mapQuest.at(indexPage).at(num)->getPrivateId();
    }

private:
    template<typename T>
    void registerType(int indexPage)
    {
        creators[indexPage] = [] { return std::make_shared<T>(); };
    }
    std::map<int, std::function<std::shared_ptr<Question>()>> creators;
    std::map<int, std::vector<std::shared_ptr<Question>>> mapQuest;
};