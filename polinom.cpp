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
        double* roots = p.findRoot();
        if (roots[0] < 0 ){
            os<<"No roots";
        }
        else{
            os<<p.a<<"(x-"<<roots[1]<<")"<<"(x-"<<roots[2]<<")";
        }
    }
    return os;
}
number TPolinom::value(number x){
    return a*x*x + b*x + c;
}
void  TPolinom::setPrintMode(EPrintMode m){
   printMode = m;
}
double * TPolinom::findRoot(){
    double  D;
    static  double result[3];
    D = b*b-4*a*c;
    result[0] = D;
    if (D >= 0) {
        result[1] = (-b-sqrt(D))/(2*a);
        result[2] = (-b+sqrt(D))/(2*a);
    }
    return result;

}
