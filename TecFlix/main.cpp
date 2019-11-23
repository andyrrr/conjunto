#include "interfaz.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <pelicula.h>

using namespace std;
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Interfaz w;
    w.show();

    return a.exec();
}
