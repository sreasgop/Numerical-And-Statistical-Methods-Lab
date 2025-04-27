// QUESTION:
/* Using Euler's method, write a C program to determine
 the value of y correct upto 4 decimal places when x=0.04
 given that y'=-y, y(0)=1 [Take the step-size h=0.01]
 File created by: Dr. Suddhyashil Sarkar*/



// CODE:
#include<stdio.h>
#define f(x,y) -y

int main(){
    
    float x0,y0,h,xn;
    int i,n;
    
    printf("\nEnter the values of x0,y0,h,xn, respectively: ");
    scanf("%f%f%f%f",&x0,&y0,&h,&xn);
    
    n=(xn-x0)/h;
    float x[n+1],y[n+1];
    
    x[0]=x0;
    y[0]=y0;
    
    for(i=0;i<n;i++){
        x[i+1]=x[i]+h;
        y[i+1]=y[i]+h*f(x[i],y[i]);
    }
    
    printf("By Euler's method, y(%.2f)=%.4f",x[n],y[n]);
    
    return 0;
}



// OUTPUT:
// Enter the values of x0,y0,h,xn, respectively:
// 0
// 1
// 0.01
// 0.04
// By Euler's method, y(0.04)=0.9606
