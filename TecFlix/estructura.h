#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H
#include <QWidget>
#include <pelicula.h>
#include <QMouseEvent>
#include <QToolButton>

class Estructura;


class Estructura: public QWidget
{
    Q_OBJECT
public slots:
    void recibir();
public:
    Estructura(QToolButton*);
    void setPelicula(pelicula);
    QToolButton *boton;
    pelicula peli;
};

#endif // ESTRUCTURA_H
