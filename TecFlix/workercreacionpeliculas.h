#ifndef WORKERCREACIONPELICULAS_H
#define WORKERCREACIONPELICULAS_H

#include <QObject>
#include <QThread>

using namespace std;

class workerCreacionPeliculas: public QThread
{
    Q_OBJECT

public:
    explicit workerCreacionPeliculas(QObject *parent=0);
signals:
    void paginaCreada();
protected:
    void run() override;
};

#endif // WORKERCREACIONPELICULAS_H
