#ifndef INICIO_H
#define INICIO_H

#include <QMainWindow>

namespace Ui {
class inicio;
}

class inicio : public QMainWindow
{
    Q_OBJECT

public:
    explicit inicio(QWidget *parent = nullptr);
    ~inicio();

private slots:
    void on_arbolBinario_clicked();

    void on_listaEnlazada_clicked();

private:
    Ui::inicio *ui;
};

#endif // INICIO_H
