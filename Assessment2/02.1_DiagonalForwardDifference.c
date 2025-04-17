/* 2. Write a C program to construct the diagonal forward and backward difference table.
*/



// (Diagonal Forward Difference Table)
// CODE:
#include <stdio.h>

int main() {
    int n, i, j;
    
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    
    int x[n], y[n][n];
    printf("X\tY\n");
    for (i = 0; i < n; i++) {
        scanf("%d%d", &x[i], &y[i][0]);
    }
    
    // Compute forward differences
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }
    
    // Print diagonal forward difference table
    printf("\n********** Diagonal Forward Difference Table **********\n");
    for (i = 0; i < n; i++) {
        // Print main line (x, y, even-order differences)
        printf("%d\t%d", x[i], y[i][0]);

        for (j = 2; j < n; j += 2) {
            int i_prev = i - j / 2;
            if (i_prev >= 0 && (i_prev + j) < n) {
                printf("\t\t\t%d", y[i_prev][j]);
            } else {
                printf("\t\t");
            }
        }
        printf("\n");
        
        // Check if odd differences exist for this row
        int has_odd = 0;
        for (int j_odd = 1; j_odd < n; j_odd += 2) {
            int i_prev_odd = i - (j_odd - 1) / 2;
            if (i_prev_odd >= 0 && (i_prev_odd + j_odd) < n) {
                has_odd = 1;
                break;
            }
        }
        
        // Print odd line only if differences exist
        if (has_odd) {
            printf("\t"); // Initial indent
            for (j = 1; j < n; j += 2) {
                int i_prev = i - (j - 1) / 2;
                if (i_prev >= 0 && (i_prev + j) < n) {
                    printf("\t\t%d", y[i_prev][j]);
                } else {
                    printf("\t");
                }
            }
            printf("\n");
        }
    }
    return 0;
}



// OUTPUT: 
// Enter the number of data points: 5
// X       Y
// 0       1
// 1       3
// 2       9
// 3       31
// 4       81

// ********** Diagonal Forward Difference Table **********
// 0       1
//                         2
// 1       3                       4
//                         6               12
// 2       9                       16                      0
//                         22              12
// 3       31                      28
//                         50
// 4       81