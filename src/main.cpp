#include <qapplication.h>
#include "mainwindow.h"

#include "gallonConverter.hpp"

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


// void task1() {
//     int countGallons = 0;
//     cout << "Ведите количество галлонов: ";
//     cin >> countGallons;
//     GalloneConverter gc(countGallons);
//     cout << "Кубический фут равен " << gc.getCapacityGallone() << endl;
//     cout << "Эквивалентный объем в кубических футах: " << gc.getTotalCapacity() << endl;
// }
// void task2(){ 
//     int distantion = 10,
//         nDistantion = 8;
//     bool alignLeft = false;

//     if(!alignLeft) swap(distantion, nDistantion);

//     cout << (alignLeft ? left : right);
//     cout << setw(distantion) << 1990 << setw(nDistantion) << 135 << endl
//          << setw(distantion) << 1991 << setw(nDistantion) << 7290 << endl
//          << setw(distantion) << 1992 << setw(nDistantion) << 11300 << endl
//          << setw(distantion) << 1993 << setw(nDistantion) << 16200 << endl;

// }
// void task3(){
//     int num = 10;
//     cout << num << '\n'
//          << (num += num) <<'\n'
//          << (--num) << '\n';
// }
// void task4(){
//     cout << R"(
//           QWidget, QGroupBox {
//           background-color: rgba(255, 255, 255, 20);   /* полупрозрачный белый */
//           border: 1px solid rgba(255, 255, 255, 40);   /* полупрозрачная рамка */
//           border-radius: 12px;                         /* скруглённые углы */
//           color: white;
//           margin-top: 8px;
//         }
//         QGroupBox::title {
//           subcontrol-origin: margin;
//           left: 10px;
//           color: rgba(255, 255, 255, 200);
//         }
//     )";
// }