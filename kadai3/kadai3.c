#include <stdio.h>
#define dt 0.05
#define maxstep 1000
#define I 0.8
#define a 0.7
#define b 0.8
#define eps 3.0


double fx(double x,double v){

    return eps * (v + x -x * x * x / 3 + I);
}
double fv(double x,double v){
    return -(x-a+b*v)/eps;
}
int main(int argc, char *argv[]){
    int step;;
    double x,v,x1,v1,x2,v2,x3,v3,x4,v4;
    x = 1.0;
    v = -1.0;
    
    for (step=0;step<maxstep;step++){
        printf("%lf %lf %lf \n",step*dt,x,v);
        x1 = fx(x,v)*dt;
        v1 = fv(x,v)*dt;
        x2 = fx(x+x1/2,v+v1/2)*dt;
        v2 = fv(x+x1,v+v1)*dt;
        x3 = fx(x+x2/2,v+v2/2)*dt;
        v3 = fv(x+x2/2,v+v2/2)*dt;
        x4 = fx(x+x3,v+v3)*dt;
        v4 = fv(x+x3,v+v3)*dt;
        x = x + (x1 + 2 * x2 + 2 * x3 + x4) / 6;
        v = v + (v1 + 2 * v2 + 3 * v3 + v4) / 6;
    }

}