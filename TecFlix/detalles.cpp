#include "detalles.h"
#include "ui_detalles.h"
#include <qdebug.h>
#include <iostream>

using namespace std;
detalles::detalles(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::detalles)
{
    ui->setupUi(this);
}
void detalles::recibir(int num){
    qDebug()<<num;
}
void detalles::modificar(pelicula p){
    ui->genero->setText(QString(p.genres.c_str()));
    ui->nombre->setText(QString(p.movie_title.c_str()));
    ui->country->setText(QString(p.country.c_str()));
    ui->numCrit->setText(QString(p.num_critic_for_reviews.c_str()));
    ui->director->setText(QString(p.director_name.c_str()));
    ui->duracion->setText(QString(p.duration.c_str()));
    ui->lenguaje->setText(QString(p.language.c_str()));
    ui->actor2name->setText(QString(p.actor_2_name.c_str()));
    ui->actor3name->setText(QString(p.actor_3_name.c_str()));
    ui->imdbscore->setText(QString(p.imdb_score.c_str()));
    ui->facebooklikes->setText(QString(p.movie_facebook_likes.c_str()));
}
detalles::~detalles()
{
    delete ui;
}
