#include "arbol.h"
#include "ui_arbol.h"
#include <iostream>
#include "empaquetar.h"
#include "QString"

using namespace std;

arbol::arbol(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::arbol)
{
    ui->setupUi(this);
}

arbol::~arbol()
{
    delete ui;
}

void arbol::on_pushButton_clicked()
{
    string num = ui->numero->toPlainText().toStdString();
    if (num == ""){
        cout<<"Error";
    } else {
        empaquetar *p = new empaquetar("AI",stoi(num),0);
        cout<<"Empaqueta"<<endl;
        Con->enviarmensaje(p);
        cout<<"termina conexión"<<endl;
        cout<<Con->getmensaje()<<endl;

        string h = Con->getmensaje();
        char static buffer[sizeof(h)];

        strcpy(buffer,h.c_str());

        ui->arbol_2->setPlaceholderText(buffer);
    }
}

void arbol::on_pushButton_2_clicked()
{
    string num = ui->numero->toPlainText().toStdString();
    if (num == ""){
        cout<<"Error";
    } else {
        empaquetar *p = new empaquetar("AE",stoi(num),0);
        cout<<"Empaqueta"<<endl;
        Con->enviarmensaje(p);
        cout<<"termina conexión"<<endl;
        cout<<Con->getmensaje()<<endl;

        string h = Con->getmensaje();
        char static buffer[sizeof(h)];

        strcpy(buffer,h.c_str());

        ui->arbol_2->setPlaceholderText(buffer);
    }

}
