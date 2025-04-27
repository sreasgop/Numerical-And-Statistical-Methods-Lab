// QUESTION:
/* Using modified Euler's method, write a C program to determine
 the value of y correct upto 4 decimal places when x=0.1 
given that y'=x^2+y, y(0)=1 [Take the step-size h=0.05]
 File created by: Dr. Suddhyashil Sarkar*/



// CODE:
#include<stdio.h>
#include<math.h>
#define f(x,y) x*x+y
int main(){

    float x0, x, y0, xn, yp, yc ,h, tol=0.00001;
    
    printf("\nEnter the values of x0,y0,h,xn, respectively:");
    scanf("%f%f%f%f",&x0,&y0,&h,&xn);

    step:
        x=x0+h; 
        if(x<=xn){
        yp=y0+h*f(x0,y0);
        yc=y0+(h/2.0)*(f(x0,y0)+f(x,yp));
        while(fabs(yp-yc)>tol){
            yp=yc;
            yc=y0+(h/2.0)*(f(x0,y0)+f(x,yp));
        }
        x0=x;
        y0=yc;
        goto step;
        }

    printf("By modified Euler's method, y(%.1f)=%.4f",xn,yc);
    return 0;

}



// OUTPUT:
// Enter the values of x0,y0,h,xn, respectively:
// 0
// 1
// 0.05
// 0.1
// By modified Euler's method, y(0.1)=1.1056
