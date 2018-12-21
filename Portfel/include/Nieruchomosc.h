#ifndef NIERUCHOMOSC_H
#define NIERUCHOMOSC_H

#include <Aktywo.h>


class Nieruchomosc : public Aktywo
{
    public:
        Nieruchomosc(double val,string val1);
        Nieruchomosc();
        virtual ~Nieruchomosc();
        double Getwartosc();
        void Setwartosc(double val);
        Nieruchomosc & operator +=(const double &val)
        {
            this->wartosc+=val;
            return * this;
        }
        Nieruchomosc & operator -=(const double val)
        {
            this->wartosc-=val;
            return * this;
        }
    protected:

    private:
        double wartosc;
};
#endif // NIERUCHOMOSC_H
