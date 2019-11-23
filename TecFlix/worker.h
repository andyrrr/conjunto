#ifndef WORKER_H
#define WORKER_H
#include <QThread>
#include <QObject>
#include <pagina.h>

class worker : public QThread
{
    Q_OBJECT

public:
    worker();
    Pagina *pag;
    void setData(int i, int t);
    bool terminoHilo();
signals:
    void enviar();
protected:
    void run();
    int tamaño;
    int id;
    bool termina;
};

#endif // WORKER_H
