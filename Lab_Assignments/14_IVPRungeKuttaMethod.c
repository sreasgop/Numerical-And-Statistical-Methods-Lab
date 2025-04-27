// QUESTION:
/* Using fourth order Runge-Kutta method, write a C program 
to determine the value of y correct upto 4 decimal places when x=0.6
 given that y'=1+y^2, y(0)=0 [Take the step-size h=0.2]
 File created by: Dr. Suddhyashil Sarkar*/



// CODE:
#include<stdio.h>

float f(float x,float y){
    return (1+y*y);
}

int main(){

    int i,n;
    float x0,y0,h,xn,k1,k2,k3,k4;

    printf("\nEnter the values of x0,y0,h,xn respectively: ");
    scanf("%f%f%f%f",&x0,&y0,&h,&xn);

    n=(xn-x0)/h;
    float x[n+1],y[n+1];
    x[0]=x0;
    y[0]=y0;

    for(i=0;i<n;i++){
        x[i+1]=x[i]+h;
        k1 = h*f(x[i], y[i]);
        k2 = h*f(x[i] + 0.5*h, y[i] + 0.5*k1);
        k3 = h*f(x[i] + 0.5*h, y[i] + 0.5*k2);
        k4 = h*f(x[i] + h, y[i] + k3);
        y[i+1]=y[i]+(k1 + 2*k2 + 2*k3 + k4)/6.0;
    }

    printf("By fourth-order Runge-Kutta method, y(%.1f)=%.4f",x[n],y[n]);

    return 0;

}



// OUTPUT:
// Enter the values of x0,y0,h,xn respectively:
// 0
// 0
// 0.2
// 0.6
// By fourth-order Runge-Kutta method, y(0.6)=0.6841

