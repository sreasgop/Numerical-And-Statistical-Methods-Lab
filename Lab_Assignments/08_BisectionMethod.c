// QUESTION:
/* Write a C program to find a root of the equation 10^x+x-4=0 
 in between 0.5 and 0.6 by Bisection method correct upto 4 decimal places.
*/



// CODE:
#include<stdio.h>
#include<math.h>

float f(float x){
    return (pow(10,x)+x-4);
}

int main(){
    float a[100],b[100],x[100];
    int n;

    printf("Enter the values of a and b respectively:\n");
    scanf("%f%f",&a[0],&b[0]);

    x[0]=a[0];
    n=0;
    x[1]=(a[0]+b[0])/2;

    if(f(a[0])*f(x[1])<0.0){
        a[1]=a[0];
        b[1]=x[1];
    }
    else{
        a[1]=x[1];
        b[1]=b[0];
    }
    
    while(fabs(x[n+1]-x[n])>0.00001){
        n++;
        x[n+1]=(a[n]+b[n])/2;
        if(f(a[n])*f(x[n+1])<0.0){
            a[n+1]=a[n];
            b[n+1]=x[n+1];
        }
        else{
            a[n+1]=x[n+1];
            b[n+1]=b[n];
        }
    }
    
    printf("\nThe required root is %.4f",x[n+1]);
    return 0;
}



// OUTPUT:
/*
Enter the values of a and b respectively:
0.5     0.6

The required root is 0.5392
*/
