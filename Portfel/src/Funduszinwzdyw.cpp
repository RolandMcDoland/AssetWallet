#include "Funduszinwzdyw.h"
#include<iostream>

using namespace std;

Funduszinwzdyw::Funduszinwzdyw(double val1,double val2,string val3)
{
    this->Setwartosc(val1);
    dywidenda=val2;
    this->Setnazwa(val3);
}
Funduszinwzdyw::Funduszinwzdyw()
{

}
Funduszinwzdyw::~Funduszinwzdyw()
{
    //dtor
}
double Funduszinwzdyw::Getdywidenda()
{
    return dywidenda;
}
void Funduszinwzdyw::Setdywidenda(double val)
{
    dywidenda=val;
}
