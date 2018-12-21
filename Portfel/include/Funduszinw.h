#ifndef FUNDUSZINW_H
#define FUNDUSZINW_H
#include<iostream>

#include <Aktywo.h>

using namespace std;

class Funduszinw : public Aktywo
{
    public:
        Funduszinw(double val,string val1);
        Funduszinw();
        virtual ~Funduszinw();
        double Getwartosc();
        void Setwartosc(double val);
        Funduszinw & operator +=(const double &val)
        {
            this->wartosc+=val;
            return * this;
        }
        Funduszinw & operator -=(const double val)
        {
            this->wartosc-=val;
            return * this;
        }
    protected:
    private:
        double wartosc;
};

#endif // FUNDUSZINW_H
