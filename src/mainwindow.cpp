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

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->codeFileNameLabel->setText("shapes_demo.cpp");
    setBackgroundImage(":/res/image/white_back.png"); // дефолтная картинка
    updateBackground();
    fitCodeEditHeight();
    setupSideBar();
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

void MainWindow::on_pushButton_clicked()
{

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

void MainWindow::fitCodeEditHeight() // метод, отвечающий за кодовый редактор
{
    QPlainTextEdit *edit = ui->codeTextEdit;
    QFontMetrics fm(edit->font());
    int lineCount = edit->document()->blockCount();
    int contentHeight = fm.lineSpacing() * lineCount + 28; // +28 — небольшой запас под padding
    edit->setFixedHeight(contentHeight);
}