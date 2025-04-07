#include <stdio.h>

#define MAX 20

int main() {
    int n;
    int x[MAX], y[MAX][MAX], value, result;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("X\tY\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
        scanf("%d", &y[i][0]);
    }

    printf("Enter value of x to find f(x): ");
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