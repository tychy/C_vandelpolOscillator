#include <stdio.h>
#include  <math.h>
#define dt 0.01
#define maxstep 1000
#define m 1.0
#define k 1.0
#define gamma 0.0

double fx(double x,double v){
    float w = k / m;
    return x + (v - dt * w * x) * dt / (1 + w * dt * dt);
}
double fv(double x,double v){
    float w = k / m;
    return (v - dt * w * x) / (1 + w * dt * dt);
}
int main(){
    int step;;
    double x,v,xnew,vnew;
    x = 1.0;
    v = 0.0;
    for (step=0;step<maxstep;step++){
        printf("%lf %lf %lf %lf \n",step*dt,x,v,cos(dt*step)-x);
        xnew = fx(x,v);
        vnew = fv(x,v);
        x = xnew;
        v = vnew;
    }

}