// QUESTION:
// 2. Write a C program to solve the following system of linear
// equations by Gauss-Seidel method:
// 10x - 2x₂ - x₃ - x₄ = 3
// —2x₁+ 10x₂- x₃ - x₄ = 15
// -x₁ - x₂ + 10x₃ - 2x₄ = 27
// -x₁ - x₂ - 2x₃ + 10x₄ = -9



// CODE:
#include <stdio.h>
#include <math.h>

int main() {
    double x1 = 0.0, x2 = 0.0, x3 = 0.0, x4 = 0.0;
    double tol = 0.0001;
    int max_iter = 100;
    int converged = 0;

    // Print header
    printf("Iteration\tx1\t\tx2\t\tx3\t\tx4\n");
    printf("=======================================================================\n");
    printf("Initial\t\t%.4f\t\t%.4f\t\t%.4f\t\t%.4f\n", x1, x2, x3, x4);

    for (int iter = 1; iter <= max_iter; iter++) {
        // Store previous values
        double prev_x1 = x1;
        double prev_x2 = x2;
        double prev_x3 = x3;
        double prev_x4 = x4;

        // Update values using Gauss-Seidel formula
        x1 = (3 + 2*x2 + x3 + x4) / 10.0;
        x2 = (15 + 2*x1 + x3 + x4) / 10.0;
        x3 = (27 + x1 + x2 + 2*x4) / 10.0;
        x4 = (-9 + x1 + x2 + 2*x3) / 10.0;

        // Print current iteration
        printf("%d\t\t%.4f\t\t%.4f\t\t%.4f\t\t%.4f\n", 
              iter, x1, x2, x3, x4);

        // Check convergence
        double diff1 = fabs(x1 - prev_x1);
        double diff2 = fabs(x2 - prev_x2);
        double diff3 = fabs(x3 - prev_x3);
        double diff4 = fabs(x4 - prev_x4);

        if (diff1 < tol && diff2 < tol && diff3 < tol && diff4 < tol) {
            converged = 1;
            break;
        }
    }

    // Final output
    printf("\nConverged Solution:\n");
    //printf("x1 = %.4f\nx2 = %.4f\nx3 = %.4f\nx4 = %.4f\n", 
    //      x1, x2, x3, x4);
    printf("x1 = %.4f\nx2 = %.4f\nx3 = %.4f\nx4 = %.4f\n", 
      x1, x2, x3, (fabs(x4) < 1e-5) ? 0.0 : x4); // Force 0.0000 for x4

    return 0;
}



// OUTPUT:
// Iteration       x1              x2              x3              x4
// =======================================================================
// Initial         0.0000          0.0000          0.0000          0.0000
// 1               0.3000          1.5600          2.8860          -0.1368
// 2               0.8869          1.9523          2.9566          -0.0248
// 3               0.9836          1.9899          2.9924          -0.0042
// 4               0.9968          1.9982          2.9987          -0.0008
// 5               0.9994          1.9997          2.9998          -0.0001
// 6               0.9999          1.9999          3.0000          -0.0000
// 7               1.0000          2.0000          3.0000          -0.0000
//
// Converged Solution:
// x1 = 1.0000
// x2 = 2.0000
// x3 = 3.0000
// x4 = 0.0000
