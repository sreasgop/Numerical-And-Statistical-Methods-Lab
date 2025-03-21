// (Diagonal Backward Difference Table)
// CODE:

#include <stdio.h>
int main()
{

    int n, i, j;
    printf("Enter the number of arguments: ");
    scanf("%d", &n);

    int x[n], y[n][n];
    printf("X\tY\n");
    for (i = 0; i < n; i++)
        scanf("%d%d", &x[i], &y[i][0]);

    for (j = 1; j < n; j++){
        for (i = n - 1; i > j - 1; i--)
            y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
    }

    // Printing the Diagonal Backward Difference Table in the required format:
    printf("\n********** Diagonal Backward Difference Table **********\n");
    for (int i = 0; i < n; i++){
        // Main line: x, y, and even-order differences
        printf("%d\t%d", x[i], y[i][0]);

        // Print even-order differences (j=2,4,6...)
        for (int j = 2; j < n; j += 2){
            int row = (n - 1) - (i - j / 2);
            if (row >= 0 && row < n && j <= row){
                printf("\t\t\t%d", y[row][j]);
            }
            else{
                printf("\t");
            }
        }
        printf("\n");

        // Check if odd differences exist for this row
        int has_odd = 0;
        for (int j_odd = 1; j_odd < n; j_odd += 2){
            int row_odd = (n - 1) - (i - (j_odd - 1) / 2);
            if (row_odd >= 0 && row_odd < n && j_odd <= row_odd){
                has_odd = 1;
                break;
            }
        }

        // Print odd line only if differences exist
        if (has_odd){
            printf("\t");
            for (int j = 1; j < n; j += 2){
                int row = (n - 1) - (i - (j - 1) / 2);
                if (row >= 0 && row < n && j <= row){
                    printf("\t\t%d", y[row][j]);
                }
                else{
                    printf("\t");
                }
            }
            printf("\n");
        }
    }

    return 0;
}

// OUTPUT:
