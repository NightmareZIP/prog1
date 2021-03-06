#ifndef TPOLINOM_H
#define TPOLINOM_H

#include "number.h"
#include <iostream>
#include <math.h>       /* sqrt */
using namespace std;

enum EPrintMode{
    EPrintModeClassic,
    EPrintModeCanonic,
};

class TPolinom
{
    EPrintMode printMode;
    number a,b,c;
    string first_sign, second_sign;
public:
    TPolinom(number, number, number);
    friend ostream& operator<<(ostream&, TPolinom&);
    number value(number);
    void setPrintMode(EPrintMode);
    double* findRoot();

};

#endif // TPOLINOM_H
