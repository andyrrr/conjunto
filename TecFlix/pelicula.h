#ifndef PELICULA_H
#define PELICULA_H

#include <vector>
#include <string>
#include <QString>
#include <QPixmap>

#include <conexion.h>

using namespace std;

class pelicula
{
public:
    pelicula();
    pelicula(vector<string>);
    void verVector(vector<string>);
    string toString();

    string getLink();
    void añadirPosterTrailer(string link);



    QString getPosterLink();

    string color, director_name, num_critic_for_reviews, duration,
    director_facebook_likes, actor_3_facebook_likes,
    actor_2_name, actor_1_facebook_likes, gross, genres,
    actor_1_name, movie_title, num_voted_users,
    cast_total_facebook_likes,
    actor_3_name, facenumber_in_poster,
    plot_keywords, movie_imdb_link, num_user_for_reviews,
    language, country, content_rating,
    budget, title_year, actor_2_facebook_likes,
    imdb_score, aspect_ratio, movie_facebook_likes;

    string LinkTrailer;
    string LinkPoster;

    QPixmap image;

    void setLinkTrailer(string link);
    void setLinkPoster(string link);
    QPixmap getimage();

    void* operator new(size_t size);
    void operator delete(void*);

public slots:
    void networkmanager(QNetworkReply *reply);
};

#endif // PELICULA_H
