#include "polinom.h"

TPolinom::TPolinom(number x, number y, number z)
{
    printMode = EPrintModeClassic;
    a = x;
    b = y;
    c = z;
    if (b >= 0){
        first_sign = '+';
    }
    else{
        first_sign = "";
    }
    if (c >=  0){
        second_sign = '+';
    }
    else{
        second_sign = "";
    }
}
ostream& operator<< (ostream& os, TPolinom& p){
    if (p.printMode == EPrintModeClassic){
        //os<<p.a<<"x^2+"<<p.b<<"x+"<<p.c;
        os<<p.a<<"x^2"<<p.first_sign<<p.b<<"x"<<p.second_sign<<p.c;

    }
    else{
        os<<p.a<<"(x-x1"<<")"<<"(x-x2"<<")";
    }
    return os;
}
number TPolinom::value(number x){
    return a*x*x + b*x + c;
}
void  TPolinom::setPrintMode(EPrintMode m){
   printMode = m;
}
void TPolinom::findRoot(){
    double  D;
    D = b*b-4*a*c;
    if (D < 0){
        cout << "No roots"<<endl;
    }
    else if (D == 0){
        cout << (-b)/(2*a)<<endl;
    }
    else {
        cout << "first root "<<(-b-sqrt(D))/(2*a)<<endl;
        cout << "first root "<<(-b+sqrt(D))/(2*a)<<endl;
    }
}
