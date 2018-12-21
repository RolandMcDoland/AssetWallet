#include "Funduszinw.h"

Funduszinw::Funduszinw(double val,string val1)
{
    wartosc=val;
    this->Setnazwa(val1);
}
Funduszinw::Funduszinw()
{

}
Funduszinw::~Funduszinw()
{
    //dtor
}
double Funduszinw::Getwartosc()
{
    return wartosc;
}
void Funduszinw::Setwartosc(double val)
{
    wartosc=val;
}
/*void operator Funduszinw::+=(double val)
{
    wartosc=wartosc+val;
}
Funduszinw::operator -=(double val)
{
    wartosc=wartosc-val;
}*/
