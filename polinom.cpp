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
        number* roots = p.findRoot();
        if (true){ //roots[0] < 0 ){
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
number * TPolinom::findRoot(){
    number  D;
    static  number result[3];
    D = b*b-a*c*4;
    result[0] = D;
    if (D >= 0) {
        result[1] = (-b-sqrt(D))/(a*2);
        result[2] = (-b+sqrt(D))/(a*2);
    }
    return result;

}
