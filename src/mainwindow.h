#pragma once
#include <qmainwindow.h>
#include <qtconfigmacros.h>
#include <qtmetamacros.h>


QT_BEGIN_NAMESPACE
namespace Ui{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parrent = nullptr);
    ~MainWindow();
    void setBackgroundImage(const QString &path);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    void updateBackground();
    void goToPage(int index);

    Ui::MainWindow *ui;
    QPixmap m_originalPixmap;
    QTimer *progressTimer;      // тайммер обновления  прогресс бара

private slots:
    void q_groupBox();
    void setupSideBar(); // новый метод
    void updateProgress();
    void fitCodeEditHeight();
    
    void on_pushButton_1_clicked();   // "Назад" page 1
    void on_pushButton_2_clicked(); // "Ответить" page 1
    void on_pushButton_3_clicked(); // "Пропустить" page 1

    void on_pushButton_4_clicked(); // "Назад" page 2
    void on_pushButton_5_clicked(); // "Ответить" page 2
    void on_pushButton_6_clicked(); // "Пропустить" page 2

    void on_pushButton_7_clicked(); // "Назад" page 3
    void on_pushButton_8_clicked(); // "Ответить" page 3
    void on_pushButton_9_clicked(); // "Пропустить" page 3
};