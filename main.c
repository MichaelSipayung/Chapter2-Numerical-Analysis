#include <stdio.h>
#include "bisection.h"
int main() {
    printf("Numerical analysis\n");
    printf("bisection root \t: %.7f\n" ,
           bisection(pow(10,-4.0),100,1.0,2.0));
    return 0;
}
double f(double x){
    return pow(x,3.0)+4*pow(x,2.0)-10;
}
double bisection(double tolerance ,int maxIter,double lower,double upper){
    FILE *bisec;
    bisec=fopen("bisec.txt","w");
    int i=0;
    double p,fp,fb;
    double fa=f(lower);
    fprintf(bisec,"\t... Bisection Method ... \n");
    while (i<maxIter){
        if(f(lower)*f(upper) >0){break;}
        //else
        p=lower+(upper-lower)/2.0;
        fp=f(p);
        fprintf(bisec,"Iteration %d \tf(x) %.7f\n",i, fabs(fp));
        if((fp ==0.0)|| (fabs((upper-lower)/2.0)) < tolerance){
            printf("Total interation \t: %d\n" , i);
            printf("f(x) value \t: %.7f\n", fabs(fp));
            printf("Tolerance \t: %0.7f\n", fabs(upper-lower));
            return p;
            break;
        }
        else{
            ++i;
            if((fa*fp)>0.0){
                lower=p;
            }
            else{
                upper=p;
            }
        }
    }
    fclose(bisec);
    return -1.0;
}

