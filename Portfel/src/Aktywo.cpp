#include "Aktywo.h"
#include<iostream>
#include<string>

using namespace std;

Aktywo::Aktywo()
{
    //ctor
}

Aktywo::~Aktywo()
{
    //dtor
}
string Aktywo::Getnazwa()
{
    return nazwa;
}
void Aktywo::Setnazwa(string val)
{
    nazwa = val;
}
