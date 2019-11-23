#include "stats.h"
#include "ui_stats.h"

Stats::Stats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stats)
{
    ui->setupUi(this);
    QPalette palette;
    //change some color roles
    palette.setColor(QPalette::Window, QColor(152, 251, 152));
    this->setPalette(palette);
}

void Stats::setPoblacion(Poblacion *pob)
{
    Pobla = pob;
}

Poblacion* Stats::getPobla()
{
    return Pobla;
}

void Stats::setData()
{
    //ui->label_Est->setText(Pobla.);
    ui->label_Gen->setText(QString::number(getGen()));
    ui->label_Inv->setText(QString::number(Pobla->getProbaInv(), 'f', 7) + " / 0");
    ui->label_Mut->setText(QString::number(Pobla->getProbaMut(), 'f', 7) + " / " + QString::number(Pobla->getMutantes()));
    ui->Nombre1->setText(QString::fromStdString(getEst()->recorrer(0)->getNombre()));
    ui->Nombre2->setText(QString::fromStdString(getEst()->recorrer(1)->getNombre()));
    ui->Nombre3->setText(QString::fromStdString(getEst()->recorrer(2)->getNombre()));
    ui->Nombre4->setText(QString::fromStdString(getEst()->recorrer(3)->getNombre()));
    ui->Nombre5->setText(QString::fromStdString(getEst()->recorrer(4)->getNombre()));
    ui->Nombre6->setText(QString::fromStdString(getEst()->recorrer(5)->getNombre()));
    ui->Nombre7->setText(QString::fromStdString(getEst()->recorrer(6)->getNombre()));
    ui->Nombre8->setText(QString::fromStdString(getEst()->recorrer(7)->getNombre()));

    ui->n1->setText(QString::number(Estudiantes->recorrer(0)->getVida()));
    ui->n2->setText(QString::number(Estudiantes->recorrer(1)->getVida()));
    ui->n3->setText(QString::number(Estudiantes->recorrer(2)->getVida()));
    ui->n4->setText(QString::number(Estudiantes->recorrer(3)->getVida()));
    ui->n5->setText(QString::number(Estudiantes->recorrer(4)->getVida()));
    ui->n6->setText(QString::number(Estudiantes->recorrer(5)->getVida()));
    ui->n7->setText(QString::number(Estudiantes->recorrer(6)->getVida()));
    ui->n8->setText(QString::number(Estudiantes->recorrer(7)->getVida()));

}

Stats::~Stats()
{
    delete ui;
}

void Stats::setGen(int G)
{
    gen = G;
}

int Stats::getGen()
{
    return gen;
}

void Stats::setEst(List *Est)
{
    Estudiantes = Est;
}

List *Stats::getEst()
{
    return Estudiantes;
}
