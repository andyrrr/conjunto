#include "conexion.h"
#include <QPixmap>
#include <QDebug>

conexion::conexion(){

}
conexion::conexion(QString lin, QToolButton* di):link(lin), enInt(di)
{
    verImagen();
}

void conexion::networkmanager(QNetworkReply *reply){
    if (reply->error() != QNetworkReply::NoError){
        qDebug()<<reply->url()<<endl;
    }

    QByteArray jpegData = reply->readAll();

    imagen.loadFromData(jpegData);
    qDebug()<<imagen;


    QIcon ButtonIcon(imagen);
    enInt->setIcon(ButtonIcon);
    enInt->setIconSize(imagen.rect().size());
}

void conexion::verImagen(){
    QNetworkAccessManager * manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply *)),this, SLOT(networkmanager(QNetworkReply*)));

    QByteArray fromUrl = link.toUtf8();
    QUrl url1 = QUrl::fromEncoded(fromUrl,QUrl::StrictMode);
    QNetworkRequest request(url1);
    manager->get(request);

    //connect(enInt, SIGNAL (released()),this, SLOT (handleButton()));
}

void conexion::handleButton(){
    qDebug()<<"Toca la peli: "<<link;
}

QPixmap conexion::getImagen(){
    return imagen;
}
