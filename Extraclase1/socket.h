#ifndef SOCKET_H
#define SOCKET_H
#include "conexion.h"

#include <QMainWindow>

namespace Ui {
class Socket;
}

class Socket : public QMainWindow
{
    Q_OBJECT

public:
    explicit Socket(QWidget *parent = nullptr);
    ~Socket();

private slots:
    void on_BttnEnviar_clicked();

private:
    conexion *Con;
    Ui::Socket *ui;
};

#endif // SOCKET_H
