#include "pelicula.h"
#include "iostream"
#include <curlobj.h>

using namespace std;

pelicula::pelicula(){
}

pelicula::pelicula(vector<string> info){
    for (int i = 0; i< info.size(); i++) {
        if (i==0){
            color=info[i];
        } else if (i==1){
            director_name=info[i];
        } else if (i==2){
            num_critic_for_reviews=info[i];
        } else if (i==3){
            duration=info[i];
        } else if (i==4){
            director_facebook_likes=info[i];
        } else if (i==5){
            actor_3_facebook_likes=info[i];
        } else if (i==6){
            actor_2_name=info[i];
        } else if (i==7){
            actor_1_facebook_likes=info[i];
        } else if (i==8){
            gross=info[i];
        } else if (i==9){
            genres=info[i];
        } else if (i==10){
            actor_1_name=info[i];
        } else if (i==11){
            movie_title=info[i];
        } else if (i==12){
            num_voted_users=info[i];
        } else if (i==13){
            cast_total_facebook_likes=info[i];
        } else if (i==14){
            actor_3_name=info[i];
        } else if (i==15){
            facenumber_in_poster=info[i];
        } else if (i==16){
            plot_keywords=info[i];
        } else if (i==17){
            movie_imdb_link=info[i];
        } else if (i==18){
            num_user_for_reviews=info[i];
        } else if (i==19){
            language=info[i];
        } else if (i==20){
            country=info[i];
        } else if (i==21){
            content_rating=info[i];
        } else if (i==22){
            budget=info[i];
        } else if (i==23){
            title_year=info[i];
        } else if (i==24){
            actor_2_facebook_likes=info[i];
        } else if (i==25){
            imdb_score=info[i];
        } else if (i==26){
            aspect_ratio=info[i];
        } else if (i==27){
            movie_facebook_likes=info[i];
        }
    }
    añadirPosterTrailer(movie_imdb_link);
    //cout<<toString()<<endl;
    cout<<endl;
}

void pelicula::verVector(vector<string> info){
    for (int i = 0; i< info.size(); i++) {
        cout<<info[i]<<"//";
    }
    cout<<"\n ----------------"<<endl;
}

string pelicula::toString(){
    string final="";
    final = "color: "+ color +
            "// director_name: " + director_name +
            "// num_critic_for_review: " + num_critic_for_reviews +
            "// duration: " + duration +
            "// director_facebook_likes: " + director_facebook_likes +
            "// actor_3_facebook_likes: " +actor_3_facebook_likes +
            "// actor_2_name: "+actor_2_name +
            "// actor_1_facebook_likes: "+actor_1_facebook_likes +
            "// gross: "+gross +
            "// genres: "+genres +
            "// actor_1_name: "+actor_1_name +
            "// movie_title: "+movie_title +
            "// num_voted_users: "+num_voted_users +
            "// cast_total_facebook_likes: "+cast_total_facebook_likes +
            "// actor_3_name: "+actor_3_name +
            "// facenumber_in_poster: "+facenumber_in_poster +
            "// plot_keywords: "+plot_keywords +
            "// movie_imdb_link: "+movie_imdb_link +
            "// num_user_for_reviews: "+num_user_for_reviews +
            "// language: "+language +
            "// country: "+country +
            "// content_rating: "+content_rating +
            "// budget: "+budget +
            "// title_year: "+title_year +
            "// actor_2_facebook_likes: "+actor_2_facebook_likes +
            "// imdb_score: "+imdb_score +
            "// aspect_ratio: "+aspect_ratio +
            "// movie_facebook_likes: "+movie_facebook_likes +
            "// Poster Link: "+LinkPoster +
            "// Trailer Link: "+LinkTrailer;


    return final;
}

void pelicula::añadirPosterTrailer(string link){

    cout<<link<<endl;

    CurlObj dataHTML(link);
    string html = dataHTML.getData();
    string html2 = html;


    string buscar = "embedUrl";
    size_t lugar = html.find(buscar);

    if (lugar>html.size()){
        setLinkTrailer("Trailer No Disponible");
    } else {
        html = html.substr(lugar);

        buscar = "/";
        lugar = html.find(buscar);
        html = html.substr(lugar);


        buscar = ",";
        lugar = html.find(buscar);


        string Trailer = "https://www.imdb.com"+ html.substr(0,lugar-1);
        setLinkTrailer(Trailer);
    }
    string buscar2 = "<meta property='og:image' content=";
    size_t lugar2 = html2.find(buscar2);
    html2 = html2.substr(lugar2);


    buscar2 =" />";
    lugar2 = html2.find(buscar2);
    html2 = html2.substr(0,lugar2-1);

    buscar2 ="http";
    lugar2 = html2.find(buscar2);
    html2 = html2.substr(lugar2);
    setLinkPoster(html2);
    cout<<"Poster: "<<html2<<endl;
}

void pelicula::setLinkPoster(string link){
    LinkPoster = link;
}

QString pelicula::getPosterLink(){
    QString str = QString::fromUtf8(LinkPoster.c_str());
    return str;
}

void pelicula::setLinkTrailer(string link){
    cout<<"Trailer: "<<link<<endl;
    LinkTrailer = link;
}



void * pelicula::operator new(size_t size)
    {
        void * p = ::new pelicula();

        return p;
    }
void pelicula::operator delete(void * p)
{
    qDebug()<<"selibera pelicula";
    free(p);
}

