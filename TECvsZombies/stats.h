#ifndef STATS_H
#define STATS_H

#include <QDialog>
#include "poblacion.h"

namespace Ui {
class Stats;
}

class Stats : public QDialog
{
    Q_OBJECT

public:
    explicit Stats(QWidget *parent = nullptr);
    void setPoblacion(Poblacion *pob);
    Poblacion* getPobla();
    void setData();
    ~Stats();

    void setGen(int G);
    int getGen();
    void setEst(List* Est);
    List* getEst();

private:
    Ui::Stats *ui;
    Poblacion *Pobla;
    int gen;
    List* Estudiantes;
};

#endif // STATS_H
