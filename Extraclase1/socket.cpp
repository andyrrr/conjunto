#include "socket.h"
#include "ui_socket.h"

Socket::Socket(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Socket)
{
    ui->setupUi(this);
}

Socket::~Socket()
{
    delete ui;
}

void Socket::on_BttnEnviar_clicked()
{

    Con->enviarmensaje((ui->mensajeu->toPlainText()).toStdString());
    ui->mensajeServer->setText("Hola");

}
