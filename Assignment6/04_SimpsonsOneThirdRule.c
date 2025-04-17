// QUESTION: 
// A solid of revolution is formed by rotating about the x-axis 
// the area between the x-axis, the area between the x-axis, 
// the lines x=0 and x=1, and a curve though the points with 
// the following co-ordinates: 
// x        y 
// 0.00     1.0000 
// 0.25     0.9896 
// 0.50     0.9589 
// 0.75     0.9089 
// 1.00     0.8415 
// If 𝑉 is the volume of the solid formed, then  
// 
// 𝑉 =𝜋∫₀¹𝑦²𝑑𝑥. Write a C program to estimate the volume 
// of the solid formed by Simpson’s one-third rule, correct to 
// four decimal places.



// CODE:
#include <stdio.h>
#include <math.h>

int main() {

    int n, i;

    printf("\nEnter the number of co-ordinates: ");
    scanf("%d", &n);

    float x[n], y[n], h, sum, volume;

    printf("x\ty\n");
    for (i = 0; i < n; i++){
        scanf("%f%f", &x[i], &y[i]);
    }

    h = x[1] - x[0];
    sum = 0;

    for (int i = 0; i < n; i++) {
        y[i] = y[i] * y[i];  // y^2
    }

    for (int i = 1; i < n - 1; i++) {
        if (i % 2 == 0)
            sum += 2 * y[i];
        else
            sum += 4 * y[i];
    }

    sum += y[0] + y[n - 1];
    volume = (h / 3) * sum * M_PI;

    printf("\nEstimated volume using Simpson's 1/3 Rule = %.4f\n", volume);
    return 0;
}



// OUTPUT: 
// Enter the number of co-ordinates: 5
// x       y
// 0.00    1.0000
// 0.25    0.9896
// 0.50    0.9589
// 0.75    0.9089
// 1.00    0.8415 

// Estimated volume using Simpson's 1/3 Rule = 2.8192