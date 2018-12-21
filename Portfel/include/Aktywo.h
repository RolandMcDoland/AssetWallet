#ifndef AKTYWO_H
#define AKTYWO_H
#include<iostream>

using namespace std;


class Aktywo
{
    public:
        Aktywo();
        virtual ~Aktywo();
        string Getnazwa();
        void Setnazwa(string val);
    protected:
    private:
        string nazwa;
};

#endif // AKTYWO_H
