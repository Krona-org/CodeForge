#include <qmainwindow.h>
#include <qnamespace.h>
#include <qpixmap.h>
#include <qpainter.h>
#include <QWidget>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stypehelper.hpp"
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include <qscrollbar.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->codeFileNameLabel->setText("shapes_demo.cpp");
    setBackgroundImage(":/res/image/white_back.png"); // дефолтная картинка
    updateBackground();
    fitCodeEditHeight();
    setupSideBar();
    //ui->stackedWidget->setCurrentWidget(0);

}

void MainWindow::setBackgroundImage(const QString &path) // метод который принимает путь картнки в качестве аргумента
{
    m_originalPixmap = QPixmap(path);
    updateBackground();
}

void MainWindow::updateBackground() // метод отвечающий ща отрисовку заднего фона ( например картинки )
{
    if (m_originalPixmap.isNull())
        return; // на случай если путь неверный

    QPixmap pm = m_originalPixmap.scaled(ui->centralwidget->size(),
                                          Qt::IgnoreAspectRatio,
                                          Qt::SmoothTransformation);
    QPainter painter(&pm);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.fillRect(pm.rect(), QColor(0, 0, 0, 150));
    painter.end();

    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(pm));
    ui->centralwidget->setPalette(palette);
    ui->centralwidget->setAutoFillBackground(true);
}

void MainWindow::resizeEvent(QResizeEvent *event) // метод отвечаюзий за растягивание заднего фона
{
    QMainWindow::resizeEvent(event); // обязательно вызвать родительский
    updateBackground();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::q_groupBox()
{

}
void MainWindow::setupSideBar() // метод, который заполняет сайдБар интерактивными кнопками
{
    QStringList items = {"Главная", "Настройки", "Профиль", "Выход", "кнопка еще " };

    for (const QString &text : items) {
        QPushButton *btn = new QPushButton(text, ui->widget_3);
        btn->setMinimumHeight(40);

        btn->setStyleSheet(StyleHelper::getStyleBtnSlideBar());
        ui->verticalLayout_2->addWidget(btn);

        connect(btn, &QPushButton::clicked, this, [text]() {
            qDebug() << "Нажата кнопка:" << text;
        });
    }
    ui->verticalLayout_2->addStretch();
}

void MainWindow::updateProgress() // метод, управляющий прогресс баром
{
    int value = ui->progressBar->value();
    if (value >= 100) {
        progressTimer->stop();
        return;
    }
    ui->progressBar->setValue(value + 1);
}

void MainWindow::fitCodeEditHeight()
{
    QPlainTextEdit *edit = ui->codeTextEdit;
    QFontMetrics fm(edit->font());
    int lineCount = edit->document()->blockCount();

    // небольшой запас увеличь, т.к. document margin + frame тоже съедают пиксели
    int docMargin = edit->document()->documentMargin();
    int contentHeight = fm.lineSpacing() * lineCount
                         + docMargin * 2
                         + edit->frameWidth() * 2
                         + 10; // доп. запас

    edit->setFixedHeight(contentHeight);

    // жёстко фиксируем: скроллить некуда
    edit->verticalScrollBar()->setRange(0, 0);
    edit->verticalScrollBar()->setValue(0);
}



void MainWindow::goToPage(int index)
{
    int count = ui->stackedWidget->count();
    if (index < 0 || index >= count)
        return; // защита от выхода за границы

    ui->stackedWidget->setCurrentIndex(index);

    // если у тебя прогресс-бар привязан к номеру вопроса/страницы:
    // int percent = static_cast<int>((index + 1) * 100.0 / count);
    // ui->progressBar->setValue(percent);
}

// ---- Страница 1 (page, index 0) ----
void MainWindow::on_pushButton_1_clicked() // Назад
{
    goToPage(ui->stackedWidget->currentIndex() - 1);
}

void MainWindow::on_pushButton_2_clicked() // Ответить
{
    goToPage(ui->stackedWidget->currentIndex() + 1);
}

void MainWindow::on_pushButton_3_clicked() // Пропустить
{
    goToPage(ui->stackedWidget->currentIndex() + 1);
}

// ---- Страница 2 (page_2, index 1) ----
void MainWindow::on_pushButton_4_clicked() // Назад
{
    goToPage(ui->stackedWidget->currentIndex() - 1);
}

void MainWindow::on_pushButton_5_clicked() // Ответить
{
    goToPage(ui->stackedWidget->currentIndex() + 1);
}

void MainWindow::on_pushButton_6_clicked() // Пропустить
{
    goToPage(ui->stackedWidget->currentIndex() + 1);
}

// ---- Страница 3 (page_3, index 2) ----
void MainWindow::on_pushButton_7_clicked() // Назад
{
    goToPage(ui->stackedWidget->currentIndex() - 1);
}

void MainWindow::on_pushButton_8_clicked() // Ответить
{
    goToPage(ui->stackedWidget->currentIndex() + 1);
}

void MainWindow::on_pushButton_9_clicked() // Пропустить
{
    goToPage(ui->stackedWidget->currentIndex() + 1);
}