#include "rational.h"
#include <math.h>       /* sqrt */

TRational::TRational()
{

}

TRational::TRational(const int& up)
{
    numerator = up;
    denominator = 1;
}
void TRational::NOD(){
    int up = abs(numerator);
    int down = abs(denominator);
    if (up == 0) return;
    while (up != down) {
      if (up>down) {
        up = up-down;
      }
      else {
        down = down-up;
      }
    }
    this->numerator = numerator/up;
    this->denominator = denominator/up;
}

TRational TRational::operator+(TRational c)
{
    TRational t;

    t.numerator = c.numerator*denominator+ numerator*c.denominator;
    t.denominator = denominator*c.denominator;
    t.NOD();

    return t;
}

TRational TRational::operator*(TRational c)
{
    TRational t;
    t.numerator = numerator*c.numerator;
    t.denominator = denominator*c.denominator;
    t.NOD();
    return t;
}
TRational TRational::operator*(int c)
{
    TRational t;
    t.numerator = numerator*c;
    t.denominator = denominator;
    t.NOD();
    return t;
}
TRational TRational::operator-(TRational c)
{
    TRational t;
    t.numerator = numerator*c.denominator-c.numerator*denominator;
    t.denominator = denominator*c.denominator;
    t.NOD();
    return t;
}
TRational TRational::operator-()
{
    TRational t;
    t.numerator = -numerator;
    t.denominator = denominator;
    return t;
}
TRational TRational::operator/(TRational c)
{
    TRational t;
    t.numerator = numerator*c.denominator;
    t.denominator = denominator*c.numerator;
    t.NOD();
    return t;
}
bool TRational::operator==(int c)
{
    return denominator == 1 && numerator == c;
}

bool TRational::operator<(int c)
{

    return numerator < denominator * c;
}
bool TRational::operator>=(int c)
{

    return numerator >= denominator * c;
}
TRational sqrt(TRational c)
{
    TRational t;
    t.numerator =  sqrt(c.numerator);
    t.denominator = sqrt(c.denominator);
    t.NOD();
    return t;
}


ostream& operator<<(ostream& os, TRational c){
    os<<c.numerator<<"/"<<c.denominator;
    return os;
}
istream& operator>>(istream& is, TRational& c){
    is>>c.numerator>>c.denominator;
    return is;
}

