#ifndef DETALLES_H
#define DETALLES_H

#include <QWidget>
#include <pelicula.h>

namespace Ui {
class detalles;
}

class detalles : public QWidget
{
    Q_OBJECT

public:
    explicit detalles(QWidget *parent = nullptr);
    void modificar(pelicula p);
    ~detalles();

public slots:
    void recibir(int num);

private:
    Ui::detalles *ui;
};

#endif // DETALLES_H
