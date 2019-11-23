#ifndef LISTA_H
#define LISTA_H

#include <QWidget>
#include <conexion.h>

namespace Ui {
class lista;
}

class lista : public QWidget
{
    Q_OBJECT

public:
    explicit lista(QWidget *parent = nullptr);
    ~lista();

private slots:
    void on_BttmObtenerPosicion_clicked();

    void on_BttmInsertarInicio_clicked();

    void on_BttmEditarPosicion_clicked();

    void on_BttmEliminarInicio_clicked();

private:
    conexion *Con = new conexion();
    Ui::lista *ui;
};

#endif // LISTA_H
