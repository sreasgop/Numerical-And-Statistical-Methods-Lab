// Given the Following Table:
// x 0 1 2 3 4
// y 1 3 9 31 81

/* 1. Write a C program to construct a horizontal forward and backward difference table.
*/


// CODE: 

#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, j;

    printf("Enter the number of arguments: ");
    scanf("%d", &n);

    int x[n], yf[n][n], yb[n][n];

    printf("X\tY\n");
    for (i = 0; i < n; i++)
        scanf("%d%d", &x[i], &yf[i][0]);
        
    
    // Copying the Array:
    memcpy(yb, yf, sizeof(yf));

    // Compute Forward Difference Table
    for (j = 1; j < n; j++){
        for (i = 0; i < n - j; i++)
            yf[i][j] = yf[i + 1][j - 1] - yf[i][j - 1];
    }

    // Compute Backward Difference Table
    for (j = 1; j < n; j++){
        for (i = n - 1; i >= j; i--)
            yb[i][j] = yb[i][j - 1] - yb[i - 1][j - 1];
    }

    printf("\n********** Forward Difference Table **********\n");
    for (i = 0; i < n; i++){
        printf("\t%d", x[i]);
        for (j = 0; j < n - i; j++)
            printf("\t%d", yf[i][j]);
        printf("\n");
    }

    printf("\n********** Backward Difference Table **********\n");
    for (i = 0; i < n; i++){
        printf("\t%d", x[i]);
        for (j = 0; j <= i; j++)
            printf("\t%d", yb[i][j]);
        printf("\n");
    }

    return 0;
}

// OUTPUT: 
// Enter the number of arguments: 5
// X       Y
// 0       1
// 1       3
// 2       9
// 3       31
// 4       81

// ********** Forward Difference Table **********
//         0       1       2       4       12      0
//         1       3       6       16      12
//         2       9       22      28
//         3       31      50
//         4       81

// ********** Backward Difference Table **********
//         0       1
//         1       3       2
//         2       9       6       4
//         3       31      22      16      12
//         4       81      50      28      12      0