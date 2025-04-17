// QUESTION: 
// Implementing Trapezoidal rule, write a C program to 
// compute the area bounded by the curve y=f(x) and the x
// axis from x=7.47 to x=7.52 correct to four decimal places, 
// given that: 
// x    7.47    7.48    7.49    7.50    7.51    7.52
// f(x) 1.93    1.95    1.98    2.01    2.03    2.06



// CODE: 
#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter the number of intervals: ");
    scanf("%d", &n);

    float x[n], y[n], h, area;

    printf("x\tf(x)\n");
    for (i = 0; i < n; i++){
        scanf("%f%f", &x[i], &y[i]);
    }
    
    h = x[1] - x[0];
    area = 0;

    for (int i = 1; i < n - 1; i++) {
        area += y[i];
    }

    area += (y[0] + y[n - 1]) / 2.0;
    area *= h;

    printf("\nArea using Trapezoidal Rule = %.4f\n", area);
    return 0;
}



// OUTPUT: 
// Enter the number of intervals: 6
// x       f(x)
// 7.47    1.93
// 7.48    1.95
// 7.49    1.98
// 7.50    2.01
// 7.51    2.03
// 7.52    2.06

// Area using Trapezoidal Rule = 0.0997