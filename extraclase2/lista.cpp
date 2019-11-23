#include "lista.h"
#include "ui_lista.h"
#include <iostream>
#include "QString"

using namespace std;

lista::lista(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lista)
{
    ui->setupUi(this);
}

lista::~lista()
{
    delete ui;
}

void lista::on_BttmObtenerPosicion_clicked()
{
    cout<<"Posición: "<<ui->posicion->toPlainText().toStdString()<<endl;
    string pos = ui->posicion->toPlainText().toStdString();
    string num = ui->numero->toPlainText().toStdString();
    if (pos == ""){
        cout<<"Error";
    } else {
        empaquetar *p = new empaquetar("OP",0,stoi(pos));
        cout<<"Empaqueta"<<endl;
        Con->enviarmensaje(p);
        cout<<"termina conexión"<<endl;
        cout<<Con->getmensaje()<<endl;

        string h = Con->getmensaje();
        char static buffer[sizeof(h)];

        strcpy(buffer,h.c_str());

        ui->listaEnlazada->setPlaceholderText(buffer);
    }
}

void lista::on_BttmInsertarInicio_clicked()
{
    string pos = ui->posicion->toPlainText().toStdString();
    string num = ui->numero->toPlainText().toStdString();

    empaquetar *p = new empaquetar("II",stoi(num),0);

    cout<<"Empaqueta"<<endl;
    Con->enviarmensaje(p);
    cout<<"termina conexión"<<endl;
    cout<<Con->getmensaje()<<endl;

    string h = Con->getmensaje();
    char static buffer[sizeof(h)];

    strcpy(buffer,h.c_str());

    ui->listaEnlazada->setPlaceholderText(buffer);

    //cout<<"Numero: "<<ui->numero->toPlainText().toStdString()<<endl;
}

void lista::on_BttmEditarPosicion_clicked()
{
    string pos = ui->posicion->toPlainText().toStdString();
    string num = ui->numero->toPlainText().toStdString();

    empaquetar *p = new empaquetar("EP",stoi(num),stoi(pos));

    cout<<"Empaqueta"<<endl;
    Con->enviarmensaje(p);
    cout<<"termina conexión"<<endl;
    cout<<Con->getmensaje()<<endl;

    string h = Con->getmensaje();
    char static buffer[sizeof(h)];

    strcpy(buffer,h.c_str());

    ui->listaEnlazada->setPlaceholderText(buffer);

}

void lista::on_BttmEliminarInicio_clicked()
{
    string pos = ui->posicion->toPlainText().toStdString();
    string num = ui->numero->toPlainText().toStdString();

    empaquetar *p = new empaquetar("EI",0,0);

    cout<<"Empaqueta"<<endl;
    Con->enviarmensaje(p);
    cout<<"termina conexión"<<endl;
    cout<<Con->getmensaje()<<endl;

    string h = Con->getmensaje();
    char static buffer[sizeof(h)];

    strcpy(buffer,h.c_str());

    ui->listaEnlazada->setPlaceholderText(buffer);

    //cout<<"eliminado"<<endl;
}
