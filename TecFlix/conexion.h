#ifndef CONEXION_H
#define CONEXION_H

#include <QObject>

#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstdlib>
#include <netinet/in.h>
#include <QString>
#include <QPixmap>
#include <QToolButton>


#include <string>

using namespace std;


class conexion : public QObject
{
    Q_OBJECT

public:
    conexion();
    conexion(QString lin, QToolButton* di);
    void verImagen();
    QPixmap getImagen();
    QPixmap imagen;
    QString link;
    QToolButton *enInt;

public slots:
    void networkmanager(QNetworkReply *reply);
    void handleButton();


};

#endif // CONEXION_H
