#ifndef LOKATA_H
#define LOKATA_H

#include <Aktywo.h>


class Lokata : public Aktywo
{
    public:
        Lokata(double val1,double val2,string val3);
        Lokata();
        virtual ~Lokata();
        double Getstankonta();
        void Setstankonta(double val);
        double Getoprocentowanie();
        void Setoprocentowanie(double val);
        Lokata& operator +=(const double val)
        {
            this->stankonta+=val;
            return *this;
        }
        Lokata& operator -=(const double val)
        {
            this->stankonta-=val;
            return *this;
        }
    protected:
    private:
        double stankonta;
        double oprocentowanie;
};

#endif // LOKATA_H
