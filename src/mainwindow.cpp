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

    ui->codeTextEdit->setPlainText(R"(#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
    virtual void print() const = 0;
};

class Circle : public Shape {
    double radius;
public:
    explicit Circle(double r) : radius(r) {}
    double area() const override { return 3.14159 * radius * radius; }
    void print() const override {
        std::cout << "Circle with radius " << radius
                  << ", area = " << area() << std::endl;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
    void print() const override {
        std::cout << "Rectangle " << width << "x" << height
                  << ", area = " << area() << std::endl;
    }
};

int main()
{
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));

    std::sort(shapes.begin(), shapes.end(),
        [](const auto &a, const auto &b) {
            return a->area() < b->area();
        });

    for (const auto &shape : shapes) {
        shape->print();
    }

    return 0;
}
)");

ui->codeFileNameLabel->setText("shapes_demo.cpp");



    setBackgroundImage(":/res/image/white_back.png"); // дефолтная картинка
    //ui->widgetDriverList->setStyleSheet(StyleHelper::getGlassStyle());
    //ui->widgetDiagrama->setStyleSheet(StyleHelper::getGlassStyle());
    
    updateBackground();
    fitCodeEditHeight();
}

void MainWindow::setBackgroundImage(const QString &path)
{
    m_originalPixmap = QPixmap(path);
    updateBackground();
}

void MainWindow::updateBackground()
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

void MainWindow::resizeEvent(QResizeEvent *event)
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
void MainWindow::setupSideBar()
{
    // QStringList items = {"Главная", "Настройки", "Профиль", "Выход", "кнопка еще "};

    // for (const QString &text : items) {
    //     QPushButton *btn = new QPushButton(text, ui->sideBarWidget);
    //     btn->setMinimumHeight(40);
    //     ui->verticalLayout->addWidget(btn);

    //     connect(btn, &QPushButton::clicked, this, [text]() {
    //         qDebug() << "Нажата кнопка:" << text;
    //     });
    // }

    // // Чтобы кнопки не растягивались на всю высоту, а прижались к верху:
    // ui->verticalLayout->addStretch();
}

void MainWindow::updateProgress()
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
    int contentHeight = fm.lineSpacing() * lineCount + 5; // +28 — небольшой запас под padding
    edit->setFixedHeight(contentHeight);
}