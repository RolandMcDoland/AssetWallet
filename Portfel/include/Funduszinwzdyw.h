#ifndef FUNDUSZINWZDYW_H
#define FUNDUSZINWZDYW_H
#include<iostream>

#include <Funduszinw.h>

using namespace std;

class Funduszinwzdyw : public Funduszinw
{
    public:
        Funduszinwzdyw(double val1,double val2,string val3);
        Funduszinwzdyw();
        virtual ~Funduszinwzdyw();
        double Getdywidenda();
        void Setdywidenda(double val);
    protected:
    private:
        double dywidenda;
};

#endif // FUNDUSZINWZDYW_H
