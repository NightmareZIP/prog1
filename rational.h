#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;
class TRational
{
        int numerator, denominator;
public:
    TRational();
    TRational(const int&);
    void NOD();

    TRational operator+ (TRational);

    TRational operator* (TRational);
    TRational operator* (int);

    TRational operator/ (TRational);
    TRational operator- (TRational);
    TRational operator- ();
    friend  TRational sqrt(TRational);


    bool operator>= (int);
    bool operator== (int);
    bool operator< (int);





    friend ostream& operator<<(ostream&, TRational);
    friend istream& operator>>(istream&, TRational&);


};

#endif // RATIONAL_H
