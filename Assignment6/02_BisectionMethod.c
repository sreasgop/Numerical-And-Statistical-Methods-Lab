// QUESTION: 
// Write a C program to find the positive root lying between 
// 0 and 1, of the equation 𝑥 = 𝑒 ^ -𝑥 by Bisection method, 
// correct to three decimal places. 



// CODE:
#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

float f(float x) {
    return exp(-x) - x;
}

int main(){
    float a[100],b[100],x[100];
    int n;

    printf("Enter the values of a and b respectively:\n");
    scanf("%f%f", &a[0], &b[0]);

    x[0] = a[0];
    n=0;
    x[1] = (a[0] + b[0])/2;

    if(f(a[0]) * f(x[1]) < 0.0){
        a[1] = a[0];
        b[1] = x[1];
    }
    else{
        a[1] = x[1];
        b[1] = b[0];
    }
    
    while(fabs(x[n+1] - x[n]) > 0.00001){
        n++;
        x[n+1] = (a[n] + b[n]) / 2;
        if(f(a[n]) * f(x[n+1]) < 0.0){
            a[n+1] = a[n];
            b[n+1] = x[n+1];
        }
        else{
            a[n+1] = x[n+1];
            b[n+1] = b[n];
        }
    }
    
    printf("\nThe required root is %.3f", x[n+1]);
    return 0;
}



// OUTPUT: 
// Enter the interval a and b:
// 0       1

// The root is approximately: 0.567