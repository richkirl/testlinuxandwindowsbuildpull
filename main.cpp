#include <iostream>
#include <QApplication>
#include "matrixcode.hpp"
using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc,argv);
    std::cout<<"he"<<std::endl;
    matrixcode *x = new matrixcode;
    x->show();
    x->resize(800, 600);
    return a.exec();
    delete x;
    return 0;
}
