#include "Nieruchomosc.h"

Nieruchomosc::Nieruchomosc(double val,string val1)
{
    wartosc=val;
    this->Setnazwa(val1);
}
Nieruchomosc::~Nieruchomosc()
{
    //dtor
}
Nieruchomosc::Nieruchomosc()
{

}
void Nieruchomosc::Setwartosc(double val)
{
    wartosc=val;
}
double Nieruchomosc::Getwartosc()
{
    return wartosc;
}
/*Nieruchomosc::+=(double val)
{
    wartosc=wartosc+val;
}
Nieruchomosc::-=(double val)
{
    wartosc=wartosc-val;
}*/
