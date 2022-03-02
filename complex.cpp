#include "complex.h"

complex::complex()
{

}

complex::complex(const int& r)
{
    re = r;
    im = 0;
}
complex complex::operator+(complex c)
{
    complex t;
    t.re = c.re+ re;
    t.im = im*c.im;
    return t;
}

complex complex::operator*(complex c)
{
    complex t;
    t.re = re*c.re-im*c.im;
    t.im = re*c.im-im*c.re;
    return t;
}
ostream& operator<<(ostream& os, complex c){
    os<<"("<<c.re<<"+"<<c.im<<"i)";
    return os;
}
istream& operator>>(istream& is, complex c){
    is>>c.re>>c.im;
    return is;
}

