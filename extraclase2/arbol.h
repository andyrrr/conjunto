#ifndef ARBOL_H
#define ARBOL_H

#include <QWidget>
#include <conexion.h>

namespace Ui {
class arbol;
}

class arbol : public QWidget
{
    Q_OBJECT

public:
    explicit arbol(QWidget *parent = nullptr);
    ~arbol();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    conexion *Con = new conexion();
    Ui::arbol *ui;
};

#endif // ARBOL_H
