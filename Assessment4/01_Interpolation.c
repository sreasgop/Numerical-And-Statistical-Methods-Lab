// QUESTION: 
// Values of x (in degrees) and sin x is given in the following 
// table: 
// x    sin x 
// 15   0.2588190 
// 20   0.3420201 
// 25   0.4226183 
// 30   0.5 
// 35   0.5735764 
// 40   0.6427876 
// Write a C program to determine the value of sin 38 degrees.


// CODE:
#include <stdio.h>
#define MAX 20

int factorial(int n) {
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

int main() {
    int n;
    int x[MAX], value;
    float y[MAX][MAX], h, u, sum;

    printf("\nEnter number of data points: ");
    scanf("%d", &n);

    printf("X\tsin X\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &x[i]);
        scanf("%f", &y[i][0]);
    }

    printf("\nEnter the value of x to find sin(x): ");
    scanf("%d", &value);

    h = x[1] - x[0];
    u = (value - x[0]) / h;
    sum = y[0][0];

    for (int i = 1; i < n; i++)
        for (int j = 0; j < n - i; j++)
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];

    for (int i = 1; i < n; i++) {
        float u_term = 1;
        for (int j = 0; j < i; j++)
            u_term *= (u - j);

        sum += (u_term * y[0][i]) / factorial(i);
    }

    printf("Estimated value of sin(%d degree) is %.7f\n", value, sum);

    return 0;
}



// OUTPUT:
// Enter number of data points: 6
// X       sin X
// 15      0.2588190
// 20      0.3420201
// 25      0.4226183
// 30      0.5
// 35      0.5735764
// 40      0.6427876

// Enter the value of x to find sin(x): 38
// Estimated value of sin(38 degree) is 0.6156615

