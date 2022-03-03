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
        p.findRoot();
        if (p.D < 0){
            os<<"No roots";
        }
        else{
            os<<p.a<<"(x-"<<p.first_root<<")"<<"(x-"<<p.second_root<<")";
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
void TPolinom::findRoot(){
    D = b*b-a*c*4;
    if (D >= 0) {
        first_root = (-b-sqrt(D))/(a*2);
        second_root = (-b+sqrt(D))/(a*2);
        if (!(a*first_root*first_root+b*first_root+c == 0 && a*first_root*first_root+b*first_root+c == 0)){
            D = -1; //На случай если истинные корни не принадлежат заданному множеству
        }
    }

}
