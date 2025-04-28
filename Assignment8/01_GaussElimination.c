// QUESTION:
/* 1. Write a C program to solve the following system of linear equations by Gauss elimination method:
      0.0003120x₁ + 0.006032x₂ = 0.003328
      0.5000x₁ + 0.8942x₂ = 0.9471.
*/



// CODE:
#include <stdio.h>

int main() {
    int i, j, k, n = 2;
    float a[3][4], x[3], ratio;

    // Original system input
    a[1][1] = 0.0003120; a[1][2] = 0.006032; a[1][3] = 0.003328;
    a[2][1] = 0.5000;    a[2][2] = 0.8942;  a[2][3] = 0.9471;

    printf("System Of Linear Equations:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n+1;j++){
            printf("a[%d][%d] = ",i,j);
            printf("%f\t", a[i][j]);
        }
        printf("\n");
    }


    // Gauss Elimination
    for (i = 1; i <= n-1; i++) {
        for (j = i+1; j <= n; j++) {
            ratio = a[j][i]/a[i][i];
            for (k = 1; k <= n+1; k++) {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }

    // Back Substitution
    x[n] = a[n][n+1]/a[n][n];
    for (i = n-1; i >= 1; i--) {
        x[i] = a[i][n+1];
        for (j = i+1; j <= n; j++) {
            x[i] = x[i] - a[i][j]*x[j];
        }
        x[i] = x[i]/a[i][i];
    }

    // Output
    printf("\nSolution:\n");
    for (i = 1; i <= n; i++) {
        printf("x[%d] = %.4f\n", i, x[i]);
    }

    return 0;
}




// OUTPUT:
// System of Linear Equations:
// a[1][1] = 0.000312      a[1][2] = 0.006032      a[1][3] = 0.003328
// a[2][1] = 0.500000      a[2][2] = 0.894200      a[2][3] = 0.947100
//
// Solution:
// x[1] = 1.0000
// x[2] = 0.5000
