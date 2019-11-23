#include "nodo.h"
#include <crearcurso.h>
#include <tablero.h>
#include <modificarcurso1.h>
#include <QPalette>
#include <iostream>
#include <QDialog>
#include <algorithm>
#include <estudiante.h>
#include <QLabel>
#include <QPropertyAnimation>

using namespace std;

nodo::nodo(int col, int fil):x(250+col*80),y(50+fil*60),col(col),fil(fil)
{
    id= fil * 10 + col;
    Curso = nullptr;
    //boton es la torre
    boton = new QToolButton();

    //DEFINE EL TAMAÑO DE LOS BOTONES
    boton->setGeometry(x,y,45,45);
    boton->autoRaise();

    //AQUI PONE LA IMAGEN DE FONDO
    QPixmap imagenFondo(":/tileversions.png");
    imagenFondo = imagenFondo.scaled(boton->size());
    boton->setAutoFillBackground(true);

    //AQUI CREA EL COLOR DE LOS BOTONES
    QPalette palette = boton->palette();
    palette.setColor(QPalette::Button, QColor(Qt::black));
    boton->setPalette(palette);

    //LE PONE LA IMAGEN A LOS BOTONES
    boton->setIcon(imagenFondo);
    boton->setIconSize(QSize(42,42));


    //Pantalla con cursos por seleccionar
    pantallaAgregarCurso = new crearCurso();
    pantallaModificarCurso = new modificarCurso1();

    //Cuando se da click al nodo para agregar la torre
    connect(boton,SIGNAL(clicked()),this, SLOT(onClick()));

    //Cuando se escoge alguna torre, actualiza este
    connect(pantallaAgregarCurso,SIGNAL(cursoCreado()),this,SLOT(modificarNodo()));

    //Para eliminar o actualizar la torre
    connect(pantallaModificarCurso,SIGNAL(eliminarCurso()),this,SLOT(eliminar()));
    connect(pantallaModificarCurso,SIGNAL(actualizarCurso()),this,SLOT(actualizar()));
}

//Eliminar el curso del nodo
void nodo::eliminar(){
    //AQui define la imagen
    QPixmap imagenFondo(":/tileversions.png");
    imagenFondo = imagenFondo.scaled(boton->size());

    //Le setea la imagen al botón
    boton->setIcon(imagenFondo);
    boton->setIconSize(QSize(42,42));
    QPalette palette = boton->palette();
    palette.setColor(QPalette::Button, QColor(Qt::black));
    boton->setPalette(palette);

    //emite la señal
    emit cursoEliminado(this);

    //quita la pantalla de modificar
    pantallaModificarCurso->hide();
    //elimina el curso
    Curso= nullptr;
}

//SI se quiere actualizar una torre, hace esto
void nodo::actualizar(){
    //CHEQUEA EN CURSO Y DEVUELVE EL NIVEL
    if(Curso->Upgrade()){
        //PRIMER UPGRADE
        if(Curso->getUpgrade() == 2){
            //AQUI CREA EL COLOR DE LOS BOTONES
            QPalette palette = boton->palette();
            palette.setColor(QPalette::Button, QColor(Qt::blue));
            boton->setPalette(palette);

            //DEFINE EL ICONO DE LA TORRE EN EL NODO
            boton->setIconSize(QSize(42,42));
            boton->setIcon(Curso->imagen);
            pantallaModificarCurso->hide();

        }
        //SEGUNDO UPGRADE NIVEL MÁXIMO
        else{
            //MODIFICA GRAFICA CURSO
            //AQUI CREA EL COLOR DE LOS BOTONES
            QPalette palette = boton->palette();
            palette.setColor(QPalette::Button, QColor(Qt::yellow));
            boton->setPalette(palette);

            //AQUI SETEA LA IMAGEN
            boton->setIconSize(QSize(42,42));
            boton->setIcon(Curso->imagen);

            //ELIMINA LA PANTALLA DE MODIFICAR EL CURSO
            pantallaModificarCurso->hide();

        }
    }
    //MUESTRA QUE NO SE PUEDE ACTUALIZAR MÁS
    else{
        QDialog *dialogo = new QDialog();
        dialogo->setVisible(true);
        dialogo->show();
        dialogo->setGeometry(300,100,400,200);
        QLabel *texto = new QLabel("NO SE PUEDE ACTUALIZAR MÁS");

        //TEXTO DE NO SE PUEDE ACTUALIZAR MÁS
        texto->setParent(dialogo);
        texto->setGeometry(90,0,400,200);
        texto->setAlignment(Qt::AlignHCenter);
        texto->setAlignment(Qt::AlignVCenter);
        texto->setVisible(true);

        //FONDO DEL DIALOGO
        QPixmap imagenFondo(":/tileversions.png");
        imagenFondo = imagenFondo.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, imagenFondo);
        dialogo->setAutoFillBackground(true);
        dialogo->setPalette(palette);
        dialogo->saveGeometry();
    }

}

//Cuando se selecciona un nodo y se agrega un curso, genera adyacentes
void nodo::setParent(Tablero *parent){
    par = parent;
    connect(this,SIGNAL(cursoCreado(nodo*)),parent,SLOT(generarAdyacentes(nodo*)));
    connect(this,SIGNAL(cursoEliminado(nodo*)),parent,SLOT(eliminarAdyacentes(nodo*)));

    boton->setParent(parent);
}

void nodo::agregarEstudiante(Estudiante *e){
    listaEstudiantes.push_back(e);
}
//AL darle click al nodo
void nodo::onClick(){
    if (Curso==nullptr){
    pantallaAgregarCurso->show();

    //Se agrega la pantalla de eliminar y upgrade
    }else{
        pantallaModificarCurso->show();

    }
}
void nodo::eliminarEstudiante(Estudiante *e){
    std::vector<Estudiante*>::iterator position = std::find(listaEstudiantes.begin(),listaEstudiantes.end(),e);
    if (position != listaEstudiantes.end()){
        listaEstudiantes.erase(position);
    }
}
void nodo::atacar(){
    qDebug()<<"llega a atacar, cantidad: "<<listaEstudiantes.size();
    for (int est=0;est<listaEstudiantes.size();est++){
        listaEstudiantes[est]->restarResistencia(vigilante->getEvaluacion());
    }
}

bool nodo::tieneVigilante(){
    return vigilante!=nullptr;
}

//llega desde estudiante cuando se verifica que ya tiene vigilante
void nodo::solicitarEvaluacion(){
    /*qDebug()<<"di llega";
    QLabel *h = new QLabel(par);
    h->setPixmap(QPixmap(":/car.png"));
    QPropertyAnimation *animation = new QPropertyAnimation(h,"geometry");
    animation->setStartValue(QRect(0,0,100,100));
    animation->setEndValue(QRect(1000,400,100,100));
    animation->setDuration(10000);
    animation->setParent(par);
    animation->start();*/
}


//AGREGAR EL CURSO AL NODO
bool nodo::isFree(){
    return Curso==nullptr;
}


void nodo::modificarNodo(){
    //Este es el curso seleccionada
    Curso = pantallaAgregarCurso->Curso;
    Curso->x = x;
    Curso->y = y;
    Curso->id = id;
    boton->setIconSize(QSize(42,42));
    boton->setIconSize(QSize(50,50));
    boton->setIcon(Curso->imagen);

    //AQUI CREA EL COLOR DE LOS BOTONES
    QPalette palette = boton->palette();
    palette.setColor(QPalette::Button, QColor(Qt::black));
    boton->setPalette(palette);

    //Se define el tipo de torre
    emit cursoCreado(this);
    pantallaAgregarCurso->hide();
}


// Se define la torre vigilante, cual torre vigila los nodos
void nodo::setVigilante(curso* cursoSeleccionado){
    vigilante = cursoSeleccionado;

    //SI HAY UN CURSO EN UN ADYACENTE, NO LO PINTA ROJO
    if(cursoSeleccionado==nullptr){
        QPalette palette = boton->palette();
        palette.setColor(QPalette::Button, QColor(Qt::black));
        boton->setPalette(palette);

     //SI NO TIENE NINGUN CURSO PINTA ROJO
    } else if (Curso == nullptr){
        QPalette palette = boton->palette();
        palette.setColor(QPalette::Button, QColor(Qt::red));
        boton->setPalette(palette);
    }
}

