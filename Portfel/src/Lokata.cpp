#include "Lokata.h"

Lokata::Lokata(double val1,double val2,string val3)
{
    stankonta=val1;
    oprocentowanie=val2*0.01;
    this->Setnazwa(val3);
}
Lokata::Lokata()
{

}
Lokata::~Lokata()
{
    //dtor
}
double Lokata::Getstankonta()
{
    return stankonta;
}
double Lokata::Getoprocentowanie()
{
    return oprocentowanie;
}
void Lokata::Setstankonta(double val)
{
    stankonta=val;
}
void Lokata::Setoprocentowanie(double val)
{
    oprocentowanie=val*0.01;
}
/*Lokata::+=(double val)
{
    stankonta=stankonta+val;
}
Lokata::-=(double val)
{
    stankonta=stankonta-val;
}*/
