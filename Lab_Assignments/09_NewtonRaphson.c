// QUESTION:
/* Write a C program to find a root of the equation 10^x+x-4=0
 taking initial guess as 0.5 by Newton-Raphson method correct upto
 4 decimal places.
*/



// CODE:
#include<stdio.h>
#include<math.h>

float f(float x){
    return (pow(10,x)+x-4);
}

float df(float x){
    return (pow(10,x)*log(10)+1);
}

int main(){
    
    int n;
    float x[100];
    
    printf("Enter the initial guess:\n");
    scanf("%f",&x[0]);
    
    x[1]=x[0]-f(x[0])/df(x[0]);
    n=0;

    while(fabs(x[n+1]-x[n])>0.00001){
        n++;
        x[n+1]=x[n]-f(x[n])/df(x[n]);
    }
    
    printf("\nThe required root is %.4f",x[n+1]);
    return 0;
}



// OUTPUT:
/*
Enter the initial guess:
0.5

The required root is 0.5392
*/
