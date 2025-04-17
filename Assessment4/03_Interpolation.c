// QUESTION: 
// Write a C program to find f(0) given the following table: 
// x    -1    -2     2    4
// f(x) -1    -9    11    69



// CODE:
#include <stdio.h>
#define MAX 20

int main() {
    int n;
    int x[MAX], y[MAX][MAX], value, result;

    printf("\nEnter number of data points: ");
    scanf("%d", &n);

    printf("X\tY\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
        scanf("%d", &y[i][0]);
    }

    printf("\nEnter value of x to find f(x): ");
    scanf("%d", &value);

    for (int i = 1; i < n; i++)
        for (int j = 0; j < n - i; j++)
            y[j][i] = (y[j + 1][i - 1] - y[j][i - 1]) / (x[j + i] - x[j]);

    result = y[0][0];

    for (int i = 1; i < n; i++) {
        int term = y[0][i];
        for (int j = 0; j < i; j++)
            term *= (value - x[j]);
        result += term;
    }

    printf("Estimated value of f(%d) is %d\n", value, result);

    return 0;
}



// OUTPUT:
// Enter number of data points: 4
// X       Y
// -1      -1
// -2      -9
// 2       11
// 4       69

// Enter value of x to find f(x): 0
// Estimated value of f(0) is 1
