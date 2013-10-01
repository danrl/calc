#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define A(X,Y) r=t;while(*r){if(*r==X){*r=0;R m(t)Y m(++r);}r++;}
#define R return
int g;float m(char*t){char*r;char b[99];r=t;while(*r){
if(*r==40){g++;if(g==1){*r=0;sprintf(b,"%s%f",t,m(++r));R m(b);}}else if(*r==41){g--;if(g==0){*r=0;sprintf(b,"%f%s",m(t),++r);R m(b);}}r++;}A(43,+)A(45,-)A(42,*)A(47,/)R atof(t);}int main(int c,char*a[]){if(c<2)R-1;c=0;char*w=a[1],*r=a[1]-1;while(*++r)if(*r==44)*w++=46;else if(*r>=40&&*r<=57)*w++=*r;*w=0;printf("%f",m(a[1]));R 0;}
