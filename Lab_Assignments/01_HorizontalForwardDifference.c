// QUESTION:
/* Write a C program to construct a horizontal forward difference
 table corresponding to the following data
 x 0 1 2 3 4
 y 1 3 9 31 81
 File created by: Dr. Suddhyashil Sarkar */



// CODE:
#include <stdio.h>
int main() {
    int n, i, j;
    
    printf("Enter the number of arguments: ");
    scanf("%d", &n);
    
    int x[n], y[n][n];
    printf("X\tY\n");
    
    for (i = 0; i < n; i++)
        scanf("%d%d", &x[i], &y[i][0]);
    
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++)
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
    }
   
    printf("\n**********Horizontal Forward Difference Table**********\n ");
    for (i = 0; i < n; i++) {

        printf("\t%d", x[i]);
        for (j = 0; j < n - i; j++)
            printf("\t%d", y[i][j]);
        printf("\n");

    }

    return 0;
}



// Output: 
// **********Horizontal Forward Difference Table**********
//         0       1       2       4       12      0
//         1       3       6       16      12
//         2       9       22      28
//         3       31      50
//         4       81
