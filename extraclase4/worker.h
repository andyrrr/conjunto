#ifndef WORKER_H
#define WORKER_H


#include <QThread>
#include <QObject>


class worker: public QThread
{
    Q_OBJECT
public:
    explicit worker(QObject *parent = 0);
    void cambio(bool cambio);
    bool vacia;

signals:
    void progreso();
protected:
    void run() override;

};

#endif // WORKER_H
