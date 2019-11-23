#ifndef NODOM_H
#define NODOM_H


class NodoM
{
public:
    NodoM();
    void setFree(bool);
    bool getfree();

    void setActual(bool);
    bool getActual();


private:
    bool free;
    bool actual;
};

#endif // NODOM_H
