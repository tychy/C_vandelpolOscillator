#include <stdio.h>
#define dt 0.05
#define maxstep 1000
#define I -0.40
#define a 0.7
#define b 0.8
#define eps 3.0
#define k -1.0

double fx1(double x1,double x2,double v1,double v2){

    return eps * (v1 + x1 -x1 * x1 * x1 / 3 + I) + k * (x2 - x1);
}
double fv1(double x1,double x2,double v1,double v2){
    return -(x1-a+b*v1)/eps;
}
double fx2(double x1,double x2,double v1,double v2){

    return eps * (v2 + x2 -x2 * x2 * x2 / 3 + I) + k * (x1 - x2);

}
double fv2(double x1,double x2,double v1,double v2){
	double tmpa = 0.4;
    return -(x2-tmpa+b*v2)/eps;
}


int main(int argc, char *argv[]){
    int step;;
    double x,v,x1,v1,x2,v2,x3,v3,x4,v4;
    double x1new,v1new,x2new,v2new;
    double x1new_step1,v1new_step1,x2new_step1,v2new_step1;
    double x1new_step2,v1new_step2,x2new_step2,v2new_step2;
    double x1new_step3,v1new_step3,x2new_step3,v2new_step3;


    x1 = 1.5;
    v1 = 0.2;
    x2 = -1.2;
    v2 = 1.0;

    
    for (step=0;step<maxstep;step++){
        printf("%lf %lf %lf %lf %lf \n",step*dt,x1,x2,v1,v2);

        x1new = fx1(x1,x2,v1,v2)*dt;
        v1new = fv1(x1,x2,v1,v2)*dt;
        x2new = fx2(x1,x2,v1,v2)*dt;
        v2new = fv2(x1,x2,v1,v2)*dt;

        x1new_step1 = fx1(x1+x1new/2,x2+x2new/2,v1+v1new/2,v2+v2new/2)*dt;
        v1new_step1 = fv1(x1+x1new/2,x2+x2new/2,v1+v1new/2,v2+v2new/2)*dt;
        x2new_step1 = fx2(x1+x1new/2,x2+x2new/2,v1+v1new/2,v2+v2new/2)*dt;
        v2new_step1 = fv2(x1+x1new/2,x2+x2new/2,v1+v1new/2,v2+v2new/2)*dt;

        x1new_step2 = fx1(x1+x1new_step1/2,x2+x2new_step1/2,v1+v1new_step1/2,v2+v2new_step1/2)*dt;
        v1new_step2 = fv1(x1+x1new_step1/2,x2+x2new_step1/2,v1+v1new_step1/2,v2+v2new_step1/2)*dt;
        x2new_step2 = fx2(x1+x1new_step1/2,x2+x2new_step1/2,v1+v1new_step1/2,v2+v2new_step1/2)*dt;
        v2new_step2 = fv2(x1+x1new_step1/2,x2+x2new_step1/2,v1+v1new_step1/2,v2+v2new_step1/2)*dt;

        x1new_step3 = fx1(x1+x1new_step2,x2+x2new_step2,v1+v1new_step2,v2+v2new_step2)*dt;
        v1new_step3 = fv1(x1+x1new_step2,x2+x2new_step2,v1+v1new_step2,v2+v2new_step2)*dt;
        x2new_step3 = fx2(x1+x1new_step2,x2+x2new_step2,v1+v1new_step2,v2+v2new_step2)*dt;
        v2new_step3 = fv2(x1+x1new_step2,x2+x2new_step2,v1+v1new_step2,v2+v2new_step2)*dt;



        x1 = x1 + (x1new + 2 * x1new_step1 + 2 * x1new_step2 + x1new_step3) / 6;
        v1 = v1 + (v1new + 2 * v1new_step1 + 2 * v1new_step2 + v1new_step3) / 6;
        x2 = x2 + (x2new + 2 * x2new_step1 + 2 * x2new_step2 + x2new_step3) / 6;
        v2 = v2 + (v2new + 2 * v2new_step1 + 2 * v2new_step2 + v2new_step3) / 6;
    }

}