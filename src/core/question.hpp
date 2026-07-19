// core/question.hpp
#pragma once

#include <QString>
#include <vector>

struct Option
{
    QString text;
    bool isCorrect = false;
};

class Question
{
public:
    Question() : id(generateId()) {};
    Question(QString title, std::vector<Option> answers, QString explanation = "", 
             QString eyebrow = "", QString codeSnippet = "", QString codeFileName = "");
    // Геттеры для UI
    int getId() const { return id; }
    QString getTitle() const { return title; }
    QString getEyebrow() const { return eyebrow; }
    QString getCodeSnippet() const { return codeSnippet; }
    QString getExplanation() const { return explanation; }
    std::vector<Option> getAnswers() const { return answers; }

private:
    int id;
    int generateId();
    QString eyebrow;      // "// ВОПРОС 1 ИЗ 3"
    QString title;
    QString codeFileName;
    QString codeSnippet;
    QString explanation;  // текст объяснения, показывается после ответа

    std::vector<Option> answers; 
};

inline Question::Question(QString title, std::vector<Option> answers, QString explanation, 
                   QString eyebrow, QString codeSnippet, QString codeFileName)
    : id(generateId()), eyebrow(eyebrow), title(title), 
      codeFileName(codeFileName), codeSnippet(codeSnippet), 
      explanation(explanation), answers(answers) {};

inline int Question::generateId() {
    static int temp = 0;
    return temp++;
}
