// QUESTION:
/* Write a C program to solve the following system of linear equations
 correct to 4 decimal places by Gauss-Seidel method:
 12.214 x_1 + 2.367 x_2 + 3.672 x_3 = 7.814
 2.412 x_1 + 9.879 x_2 + 1.564 x_3 = 4.890
 1.876 x_1 + 2.985 x_2 - 11.620 x_3 = -0.972
 File created by : Dr. Suddhyashil Sarkar
 */



// CODE:
#include<stdio.h>
#include<math.h>
#define tol 0.00001
#define X1(x2,x3) ((7.814 -2.367*x2-3.672*x3)/12.214)
#define X2(x1,x3) ((4.890-2.412*x1 - 1.564*x3)/9.879)
#define X3(x1,x2) ((0.972+1.876*x1 +2.985*x2)/11.620)

int main(){
    
    float x1=0,x2=0,x3=0,y1,y2,y3;
    int i=0;
    
    printf("\n__________________________________________\n");
    printf("\n x1\t\t x2\t\t x3\n");
    printf("\n__________________________________________\n");
    printf("\n%f\t%f\t%f",x1,x2,x3);
    do {
        y1=X1(x2,x3),y2=X2(y1,x3),y3=X3(y1,y2);
        if(fabs(y1-x1)<tol && fabs(y2-x2)<tol && fabs(y3-x3)<tol){ 
            printf("\n__________________________________________\n");
            printf("\n\nx1 = %.4lf",y1);
            printf("\n\nx2 = %.4lf",y2);
            printf("\n\nx3 = %.4lf",y3);
            i = 1; 
        }
        else{
            x1 = y1, x2 = y2, x3 = y3;
            printf("\n%f\t%f\t%f",x1,x2,x3); 
        } 
    } while(i!=1);
    
    return 0;
}



// OUTPUT:
// 
// __________________________________________
//
//  x1              x2              x3
//
// __________________________________________
//
// 0.000000        0.000000        0.000000
// 0.639758        0.338790        0.273965
// 0.491738        0.331557        0.248210
// 0.500883        0.333401        0.250160
// 0.499939        0.333323        0.249987
// 0.500006        0.333334        0.250001
// __________________________________________
//
//
// x1 = 0.5000
//
// x2 = 0.3333
//
// x3 = 0.2500
