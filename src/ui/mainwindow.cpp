#include <qmainwindow.h>
#include <qnamespace.h>
#include <qobject.h>
#include <qpixmap.h>
#include <qpainter.h>
#include <format>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QAbstractButton>
#include <QStyle>

#include <qscrollbar.h>

#include "ui_mainwindow.h"
#include "codesize.hpp"
#include "mainwindow.h"
#include "cppsyntaxhighlighter.hpp"
#include "stypehelper.hpp"
#include "question.hpp"

#include "questTest.hpp"

namespace {

void ensureResultStyling(QWidget* w)
{
    const QString extra = QString(
        "\n#%1[resultState=\"correct\"] { border: 2px solid rgb(80, 200, 120); background-color: rgb(20, 40, 28); }"
        "\n#%1[resultState=\"wrong\"] { border: 2px solid rgb(220, 80, 80); background-color: rgb(40, 20, 20); }"
    ).arg(w->objectName());
    w->setStyleSheet(w->styleSheet() + extra);
}

void markResult(QWidget* w, const QString& state)
{
    w->setProperty("resultState", state);
    w->style()->unpolish(w);
    w->style()->polish(w);
    w->update();
}

void clearResult(QWidget* w)
{
    w->setProperty("resultState", QVariant());
    w->style()->unpolish(w);
    w->style()->polish(w);
    w->update();
}

} // namespace



MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->codeFileNameLabel->setText("shapes_demo.cpp");
    m_navigator = new PageNavigator(ui->stackedWidget);
    CodeSize::fitCodeEditHeight(ui->codeTextEdit);
    new CppSyntaxHighlighter(ui->codeTextEdit->document());

    // добавляем правила подсветки правильного/неправильного варианта каждому option-виджету
    const QList<QWidget*> optionWidgets = {
        ui->optionRadio1, ui->optionRadio2, ui->optionRadio3, ui->optionRadio4,
        ui->optionRadio1_2, ui->optionRadio2_2, ui->optionRadio3_2, ui->optionRadio4_2,
        ui->optionCheck1_3, ui->optionCheck2_3, ui->optionCheck3_3, ui->optionCheck4_3, ui->optionCheck5_3
    };
    for (QWidget* w : optionWidgets)
        ensureResultStyling(w);

    initializeFullPage();          // хардкодим вопросы в m_factory
    m_quiz = new QuizController(m_factory);

    buildQuestionNav(m_quiz->totalQuestions()); // сайдбар строится по реальному числу вопросов
    showCurrentQuestion();                       // показываем первый вопрос сразу

    // отладка вывод в консоль
    m_navigator->getCount(); //  количество страниц
}

// void MainWindow::initializeFullPage()
// {
//     // Страница 0 (page) — одиночный выбор с кодом
//     m_factory.addQuestionToPage(0, std::make_shared<QuestPageOne>(
//         "Что выведет этот код на C++?",
//         std::vector<Option>{{"0", false}, {"1", true}, {"Ошибка компиляции", false}},
//         "Статические переменные сохраняют свое значение между вызовами.",
//         "", // eyebrow больше не хранится в данных — считается динамически
//         "int foo() { static int x = 0; return x++; }"
//     ));

//     // Страница 1 (page_2) — одиночный выбор без кода
//     m_factory.addQuestionToPage(1, std::make_shared<QuestPageTwo>(
//         "Какая сложность поиска в std::map?",
//         std::vector<Option>{{"O(1)", false}, {"O(log N)", false}, {"O(N)", false}},
//         "std::map в C++ обычно реализуется как красно-черное дерево."
//     ));

//     // Страница 2 (page_3) — множественный выбор
//     m_factory.addQuestionToPage(2, std::make_shared<QuestPageThree>(
//         "Какие из этих строк равны 'abb'?",
//         std::vector<Option>{
//             {"abc", false}, {"aab", false}, {"abb", true}, {"aaa", false}, {"bbb", false}
//         },
//         "Строка должна побайтово совпадать с 'abb'."
//     ));
// }

MainWindow::~MainWindow() { delete ui;} 

void MainWindow::on_pushButton_1_clicked() { if (m_quiz->previous()) showCurrentQuestion(); }
void MainWindow::on_pushButton_2_clicked() { onAnswerButtonClicked(); }
void MainWindow::on_pushButton_3_clicked() { if (m_quiz->next()) showCurrentQuestion(); }
void MainWindow::on_pushButton_4_clicked() { if (m_quiz->previous()) showCurrentQuestion(); }
void MainWindow::on_pushButton_5_clicked() { onAnswerButtonClicked(); }
void MainWindow::on_pushButton_6_clicked() { if (m_quiz->next()) showCurrentQuestion(); }
void MainWindow::on_pushButton_7_clicked() { if (m_quiz->previous()) showCurrentQuestion(); }
void MainWindow::on_pushButton_8_clicked() { onAnswerButtonClicked(); }
void MainWindow::on_pushButton_9_clicked() { if (m_quiz->next()) showCurrentQuestion(); }

void MainWindow::onAnswerButtonClicked()
{
    if (!m_quiz->isCurrentAnswered()) {
        checkAnswer();               // первый клик — проверяем и показываем результат
    } else if (m_quiz->next()) {
        showCurrentQuestion();       // второй клик — идём к следующему вопросу
    }
}

void MainWindow::buildQuestionNav(int questionCount)
{
    QVBoxLayout* layout = ui->verticalLayout_8;

    // чистим всё, что лежало в лэйауте (пример из Designer в т.ч.)
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (item->widget())
            item->widget()->deleteLater();
        delete item;
    }

    for (int i = 0; i < questionCount; ++i) {
        auto* btn = new QPushButton(QString("Вопрос %1").arg(i + 1), this);
        btn->setMinimumHeight(20);

        connect(btn, &QPushButton::clicked, this, [this, i]() {
            if (m_quiz->goToQuestion(i))
                showCurrentQuestion();
        });

        layout->addWidget(btn, 0, Qt::AlignTop);
    }

    layout->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));
}

void MainWindow::showCurrentQuestion()
{
    auto question = m_quiz->currentQuestion();
    if (!question)
        return; 

    resetAnswerUI(); 

    const int index = m_quiz->currentIndex();
    const int total = m_quiz->totalQuestions();
    const QuestionLayout layout = m_quiz->currentLayout();
    const auto answers = question->getAnswers();

    // эпиграф всегда считаем сами по реальному числу вопросов —
    // раньше он брался из текста вопроса, где было захардкожено неверное "ИЗ N"
    QString eyebrow = QString::fromStdString(std::format("ВОПРОС {0} ИЗ {1}", index + 1, total));
    if (layout == QuestionLayout::MultiChoice)
        eyebrow += QStringLiteral(" (ВЫБЕРИТЕ НЕСКОЛЬКО ВАРИАНТОВ)");

    switch (layout) {
    case QuestionLayout::SingleChoiceCode: {
        m_navigator->goToPage(0);

        ui->questionEyebrowLabel->setText(eyebrow);
        ui->questionTitleLabel->setText(question->getTitle());
        ui->codeTextEdit->setPlainText(question->getCodeSnippet());
        CodeSize::fitCodeEditHeight(ui->codeTextEdit);

        QRadioButton* radios[] = { ui->optionRadio1, ui->optionRadio2, ui->optionRadio3, ui->optionRadio4 };
        for (int i = 0; i < 4; ++i) {
            const bool has = i < static_cast<int>(answers.size());
            radios[i]->setVisible(has);
            if (has) {
                radios[i]->setText(answers[i].text);
                radios[i]->setChecked(false);
            }
        }
        break;
    }
    case QuestionLayout::SingleChoiceText: {
        m_navigator->goToPage(1);

        ui->questionEyebrowLabel_2->setText(eyebrow);
        ui->questionTitleLabel_3->setText(question->getTitle());

        QRadioButton* radios[] = { ui->optionRadio1_2, ui->optionRadio2_2, ui->optionRadio3_2, ui->optionRadio4_2 };
        for (int i = 0; i < 4; ++i) {
            const bool has = i < static_cast<int>(answers.size());
            radios[i]->setVisible(has);
            if (has) {
                radios[i]->setText(answers[i].text);
                radios[i]->setChecked(false);
            }
        }
        break;
    }
    case QuestionLayout::MultiChoice: {
        m_navigator->goToPage(2);

        ui->questionEyebrowLabel_3->setText(eyebrow);
        ui->questionTitleLabel_4->setText(question->getTitle());

        QCheckBox* checks[] = { ui->optionCheck1_3, ui->optionCheck2_3, ui->optionCheck3_3,
                                 ui->optionCheck4_3, ui->optionCheck5_3 };
        for (int i = 0; i < 5; ++i) {
            const bool has = i < static_cast<int>(answers.size());
            checks[i]->setVisible(has);
            if (has) {
                checks[i]->setText(answers[i].text);
                checks[i]->setChecked(false);
            }
        }
        break;
    }
    }

    // прогресс-бар: сколько вопросов пройдено из общего числа
    ui->progressBar->setValue(total > 0 ? (index + 1) * 100 / total : 0);

    // если на этот вопрос уже отвечали раньше — восстанавливаем его состояние
    if (m_quiz->isCurrentAnswered())
        applyAnswerResult(m_quiz->currentSelections());
}

void MainWindow::checkAnswer()
{
    if (m_quiz->isCurrentAnswered())
        return; // результат уже показан — повторно не пересчитываем

    auto question = m_quiz->currentQuestion();
    if (!question)
        return;

    const auto answers = question->getAnswers();
    const QuestionLayout layout = m_quiz->currentLayout();

    // считываем текущий выбор пользователя прямо из виджетов
    std::vector<bool> selections(answers.size(), false);
    switch (layout) {
    case QuestionLayout::SingleChoiceCode: {
        QRadioButton* radios[] = { ui->optionRadio1, ui->optionRadio2, ui->optionRadio3, ui->optionRadio4 };
        for (int i = 0; i < static_cast<int>(selections.size()); ++i)
            selections[i] = radios[i]->isChecked();
        break;
    }
    case QuestionLayout::SingleChoiceText: {
        QRadioButton* radios[] = { ui->optionRadio1_2, ui->optionRadio2_2, ui->optionRadio3_2, ui->optionRadio4_2 };
        for (int i = 0; i < static_cast<int>(selections.size()); ++i)
            selections[i] = radios[i]->isChecked();
        break;
    }
    case QuestionLayout::MultiChoice: {
        QCheckBox* checks[] = { ui->optionCheck1_3, ui->optionCheck2_3, ui->optionCheck3_3,
                                 ui->optionCheck4_3, ui->optionCheck5_3 };
        for (int i = 0; i < static_cast<int>(selections.size()); ++i)
            selections[i] = checks[i]->isChecked();
        break;
    }
    }

    m_quiz->recordAnswer(selections); // сохраняем выбор в контроллере — переживёт переход на другой вопрос и обратно
    applyAnswerResult(selections);
}

void MainWindow::applyAnswerResult(const std::vector<bool>& selections)
{
    auto question = m_quiz->currentQuestion();
    if (!question)
        return;

    const auto answers = question->getAnswers();
    const QuestionLayout layout = m_quiz->currentLayout();
    bool allCorrect = true;

    // Отрисовывает один вариант ответа по заданному selections: подсвечивает верный
    // вариант зелёным всегда, а неверно выбранный — красным. Если верный вариант
    // не был выбран — allCorrect=false.
    auto evaluate = [&](QAbstractButton* btn, int answerIndex) {
        if (answerIndex >= static_cast<int>(answers.size()) || !btn->isVisible())
            return;

        const bool isChecked = answerIndex < static_cast<int>(selections.size()) && selections[answerIndex];
        btn->setChecked(isChecked);

        const bool isCorrectOption = answers[answerIndex].isCorrect;
        if (isCorrectOption) {
            markResult(btn, "correct");
            if (!isChecked)
                allCorrect = false;
        } else if (isChecked) {
            markResult(btn, "wrong");
            allCorrect = false;
        }
        btn->setEnabled(false); // блокируем варианты, пока не перешли к следующему вопросу
    };

    QWidget* explanationWidget = nullptr;
    QLabel* explanationEyebrow = nullptr;
    QLabel* explanationTitle = nullptr;

    switch (layout) {
    case QuestionLayout::SingleChoiceCode: {
        QRadioButton* radios[] = { ui->optionRadio1, ui->optionRadio2, ui->optionRadio3, ui->optionRadio4 };
        for (int i = 0; i < 4; ++i) evaluate(radios[i], i);
        explanationWidget = ui->widget_12;
        explanationEyebrow = ui->questionEyebrowLabel_6;
        explanationTitle = ui->questionTitleLabel_7;
        break;
    }
    case QuestionLayout::SingleChoiceText: {
        QRadioButton* radios[] = { ui->optionRadio1_2, ui->optionRadio2_2, ui->optionRadio3_2, ui->optionRadio4_2 };
        for (int i = 0; i < 4; ++i) evaluate(radios[i], i);
        explanationWidget = ui->widget_11;
        explanationEyebrow = ui->questionEyebrowLabel_5;
        explanationTitle = ui->questionTitleLabel_6;
        break;
    }
    case QuestionLayout::MultiChoice: {
        QCheckBox* checks[] = { ui->optionCheck1_3, ui->optionCheck2_3, ui->optionCheck3_3,
                                 ui->optionCheck4_3, ui->optionCheck5_3 };
        for (int i = 0; i < 5; ++i) evaluate(checks[i], i);
        explanationWidget = ui->widget_10;
        explanationEyebrow = ui->questionEyebrowLabel_4;
        explanationTitle = ui->questionTitleLabel_5;
        break;
    }
    }

    if (explanationEyebrow)
        explanationEyebrow->setText(allCorrect ? "Верно!" : "Неверно");
    if (explanationTitle)
        explanationTitle->setText(question->getExplanation());
    if (explanationWidget)
        explanationWidget->setVisible(true);
}

void MainWindow::resetAnswerUI()
{
    const QList<QAbstractButton*> allOptions = {
        ui->optionRadio1, ui->optionRadio2, ui->optionRadio3, ui->optionRadio4,
        ui->optionRadio1_2, ui->optionRadio2_2, ui->optionRadio3_2, ui->optionRadio4_2,
        ui->optionCheck1_3, ui->optionCheck2_3, ui->optionCheck3_3, ui->optionCheck4_3, ui->optionCheck5_3
    };
    for (QAbstractButton* btn : allOptions) {
        btn->setChecked(false);
        btn->setEnabled(true);
        clearResult(btn);
    }

    ui->widget_12->setVisible(false);
    ui->widget_11->setVisible(false);
    ui->widget_10->setVisible(false);
}