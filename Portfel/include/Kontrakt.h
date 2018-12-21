#ifndef KONTRAKT_H
#define KONTRAKT_H

#include <Aktywo.h>

class Kontrakt : public Aktywo
{
    public:
        Kontrakt(double val,string val1);
        Kontrakt();
        virtual ~Kontrakt();
        double Getprzychod();
        void Setprzychod(double val);
        Kontrakt & operator +=(const double &val)
        {
            this->przychod+=val;
            return * this;
        }
        Kontrakt & operator -=(const double val)
        {
            this->przychod-=val;
            return * this;
        }
    protected:
    private:
        double przychod;
};

#endif // KONTRAKT_H
