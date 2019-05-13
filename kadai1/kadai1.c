#include <stdio.h>
#include  <math.h>
#define dt 1.0e-10
#define maxstep 1000000
#define m 1.0
#define k 1.0
#define gamma 0.0

double fx(double x,double v){
    return v;
}
double fv(double x,double v){
    return - (k / m) * x;
}
int main(){
    int step;;
    double x,v,xnew,vnew;
    x = 1.0;
    v = 0.0;
    for (step=0;step<maxstep;step++){
        printf("%lf %lf %lf %lf \n",step*dt,x,v,cos(dt*step)-x);
        xnew = x + fx(x,v) * dt;
        vnew = v + fv(x,v) * dt;
        x = xnew;
        v = vnew;
    }

}