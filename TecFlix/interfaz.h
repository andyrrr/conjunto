#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QMainWindow>
#include <vector>
#include <string>
#include <pelicula.h>
#include <QtWebView/QtWebView>
#include <pagina.h>
#include <worker.h>
#include <estructura.h>

using namespace std;

namespace Ui {


class Interfaz;
}

class Interfaz : public QMainWindow
{
    Q_OBJECT

public:
    explicit Interfaz(QWidget *parent = nullptr);
    void setlistadoPeliculas(vector<pelicula> listado);
    void setEstructura();
    void boton();
    void limpiar();
    ~Interfaz();
public slots:
    void cargarPaginaActual();
    void recibir();
    void recibirSig();
    void recibirAnt();

    void click();

private slots:
    void on_ButtonAnterior_clicked();

    void on_ButtonSiguiente_clicked();

    void on_zoomin_clicked();

    void on_zoomout_clicked();


private:
    Ui::Interfaz *ui;
    vector<Estructura *> botones;
    Pagina *actual;
    Pagina *anterior;
    Pagina *siguiente;
    worker *pagSig;
    worker *pagAnt;
    worker *pagAct;
    bool esperaSiguiente;
    bool esperaAnterior;

    int filas;
    int columnas;

};

#endif // INTERFAZ_H
