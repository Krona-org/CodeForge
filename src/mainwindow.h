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
    
    Ui::MainWindow *ui;
    QPixmap m_originalPixmap;
    QTimer *progressTimer;      // тайммер обновления  прогресс бара

private slots:
    void on_pushButton_clicked();
    void q_groupBox();
    void setupSideBar(); // новый метод
    void updateProgress();
    
};