#ifndef CURLOBJ_H
#define CURLOBJ_H
#include <string>
#include <curl/curl.h>
#include <algorithm>
#include <map>
#include <iostream>
#include <vector>


using namespace std;

class CurlObj
{
public:
    CurlObj(string url);
    static int curlWriter(char *data, int size, int nmemb, string *buffer);
    string getData();

protected:
    string curlBuffer;
    CURL * curl;
};

#endif // CURLOBJ_H
