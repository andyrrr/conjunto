#ifndef INTERFAZ_H
#define INTERFAZ_H



#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QMainWindow>
#include <nodom.h>
#include <worker.h>
#include <QThread>

namespace Ui {
class Interfaz;
}

class Interfaz : public QMainWindow
{
    Q_OBJECT

public:
    explicit Interfaz(QWidget *parent = nullptr);
    void dibujar();
    void definirMatriz();
    void definirObstaculos();
    void caminar(int iini, int jini, int ifin, int jfin);
    void animacion();
    worker *pro = new worker;
    ~Interfaz();

public slots:
    void handleresul();

private slots:
    void on_obstaculos_clicked();

    void on_caminar_clicked();

private:
    Ui::Interfaz *ui;
    NodoM *matriz[100][100] {};
    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;
    QGraphicsTextItem *text;


    NodoM *actual = new NodoM();
    int iact;
    int iini;
    int jact;
    int jini;
    int ifin;
    int jfin;

};

#endif // INTERFAZ_H
