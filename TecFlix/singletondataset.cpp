#include "singletondataset.h"
#include <iostream>


SingletonDataSet* SingletonDataSet::instance=0;

SingletonDataSet::SingletonDataSet()
{leerCSV();}

SingletonDataSet* SingletonDataSet::getInstance(){

    if (instance==0){
        cout<<"Se crea el dataset"<<endl;
        instance = new SingletonDataSet();
    }
    return instance;
}



void SingletonDataSet::leerCSV(){
    ifstream myfile;

    myfile.open("/home/andy/Documentos/movie_metadata.csv");

    if (!myfile.is_open()){
        cout<< "ERROR: FILE OPEN" <<endl;

    }

    vector<string> info = {"color", "director_name" , "num_critic_for_reviews", " duration", " director_facebook_likes", " actor_3_facebook_likes",
                           "actor_2_name", " actor_1_facebook_likes", " gross", " genres", " actor_1_name", " movie_title", " num_voted_users", " cast_total_facebook_likes",
                           "actor_3_name", " facenumber_in_poster", " plot_keywords", " movie_imdb_link", " num_user_for_reviews", " language", " country", " content_rating",
                           "budget", " title_year", " actor_2_facebook_likes", " imdb_score", " aspect_ratio", "movie_facebook_likes"};


    vector<string>::iterator it;
    it = info.begin();

    while (myfile.good()) {
        vector<string> peliculaTemp={};
        for (it = info.begin() ; it < info.end(); ++it){
            if (*it != "movie_facebook_likes"){
                string dato = *it;
                getline(myfile,*it,',');
                //cout<<dato<<" : "<<*it<<" // ";
                peliculaTemp.push_back(*it);
                *it = dato;

            } else if (*it == "movie_facebook_likes"){
                string dato = *it;
                getline(myfile,*it,'\n');
                //cout<<dato<<" : "<<*it<<endl;
                //cout <<"-------------------"<<endl;
                peliculaTemp.push_back(*it);
                *it = dato;
            }
        }
        listaDePeliculas.push_back(peliculaTemp);
    }
    myfile.close();
    cout<<"varas"<<endl;
    listaDePeliculas.pop_back();
}


vector<vector<string>> SingletonDataSet::getDataset(){
    return listaDePeliculas;
}
