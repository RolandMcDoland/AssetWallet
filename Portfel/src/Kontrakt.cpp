#include "Kontrakt.h"

Kontrakt::Kontrakt(double val,string val1)
{
    przychod=val;
    this->Setnazwa(val1);
}
Kontrakt::Kontrakt()
{

}
Kontrakt::~Kontrakt()
{
    //dtor
}
double Kontrakt::Getprzychod()
{
    return przychod;
}
void Kontrakt::Setprzychod(double val)
{
    przychod = val;
}
/*Kontrakt::+=(double val)
{
    przychod=przychod+val;
}
Kontrakt::-=(double val)
{
    przychod=przychod-val;
}*/
