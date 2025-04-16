// QUESTION:
/* Write a C program to integrate 1/(1+x^2)
in between limits 0 to 1 by Simpson's one-third rule,
 taking 4 sub-intervals correct upto 4 decimal places.
 File created by: Dr. Suddhyashil Sarkar.*/



// CODE:
#include <stdio.h>

float f(float x) {
    return (1 / (1 + x * x));
}

int main() {
    int i, n;
    float a, b;
    
    printf("\nEnter the lower limit of integration: ");
    scanf("%f", &a);
    
    printf("\nEnter the upper limit of integration: ");
    scanf("%f", &b);
    
    printf("\nEnter the number of sub-intervals: ");
    scanf("%d", &n);
    
    float x0, h, x[n], y[n], so = 0.0, se = 0.0, ans;
    if (n % 2 == 1)
        printf("%d must be even", n);
    else {
        x0 = a, h = (b - a) / n;
        for (i = 0; i <= n; i++)
            x[i] = x0 + i * h, y[i] = f(x[i]);
        for (i = 1; i < n; i++)
        {
            if (i % 2 == 1)
                so = so + y[i];
            else
                se = se + y[i];
        }
        ans = (h / 3) * (y[0] + y[n] + 4 * so + 2 * se);
        printf("\nRequired integral by Simpson's one-third rule is: %.4f", ans);
    }
    return 0;
}



// OUTPUT: 

// Enter the lower limit of integration: 0

// Enter the upper limit of integration: 1

// Enter the number of sub-intervals: 4

// Required integral by Simpson's one-third rule is: 0.7854
