#ifndef SINGLETONDATASET_H
#define SINGLETONDATASET_H
#include <vector>

#include <fstream>
#include <string>
#include <vector>

using namespace std;

class SingletonDataSet
{
private:
    static SingletonDataSet* instance;
    SingletonDataSet();
    void leerCSV();
    vector<vector<string>> listaDePeliculas={};

public:
    static SingletonDataSet* getInstance();
    vector<vector<string>> getDataset();

};

#endif // SINGLETONDATASET_H
