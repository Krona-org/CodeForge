#include <qapplication.h>
#include "mainwindow.h"

using namespace std;

void task1();
void task2();
void task3();
void task4();

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    
    return a.exec();
}