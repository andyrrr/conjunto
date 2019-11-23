#include "inicio.h"
#include "ui_inicio.h"
#include <arbol.h>
#include <lista.h>

inicio::inicio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::inicio)
{
    ui->setupUi(this);
}

inicio::~inicio()
{
    delete ui;
}

void inicio::on_arbolBinario_clicked()
{
    arbol *a = new arbol();
    a->show();
    this->hide();
}

void inicio::on_listaEnlazada_clicked()
{
    lista *l = new lista();
    l->show();
    this->hide();
}
