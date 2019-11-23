#ifndef EVALUACION_H
#define EVALUACION_H
#include <QWidget>
#include <QPropertyAnimation>
#include <QLabel>
#include <QDebug>

class Evaluacion : public QWidget
{
    Q_OBJECT

public:
    Evaluacion(int , int, QLabel*);
    void evaluar(int xfinal, int yfinal);
    int corx;
    int cory;
    int id;
    QLabel *imagen=nullptr;
    bool libre;
public slots:
    void llegaEvaluacion();

signals:
    void termino();
private:
    QPropertyAnimation *animation;
};

#endif // EVALUACION_H
