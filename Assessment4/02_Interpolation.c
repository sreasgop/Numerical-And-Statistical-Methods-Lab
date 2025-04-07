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
    float x[MAX], y[MAX][MAX], value, h, u, sum;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("X\tY\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &x[i]);
        scanf("%f", &y[i][0]);
    }

    printf("Enter the value of x to evaluate y = e^(2x): ");
    scanf("%f", &value);

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

    printf("Estimated value of e^(2*%.2f) is %.4f\n", value, sum);

    return 0;
}



// OUTPUT:
// Enter number of data points: 5
// X       Y
// 0.00    1.0000
// 0.10    1.2214
// 0.20    1.4918
// 0.30    1.8221
// 0.40    2.2255
// Enter the value of x to evaluate y = e^(2x): 0.05
// Estimated value of e^(2*0.05) is 1.1052
