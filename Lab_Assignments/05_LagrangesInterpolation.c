/* Write a C program to find f(1.5) using Lagrange's interpolation
 formula having given:
 x       10.5        10.6        10.8        10.9        11.1        11.4
 f(x)    0.26969     0.33839     0.39544     0.40022     0.38332     0.32257
 File created by: Dr. Suddhyashil Sarkar */
#include <stdio.h>
int main()
{
    int n, i, j;
    
    printf("Enter the number of arguments: ");
    scanf("%d", &n);

    float x[n], y[n], X, Y = 0.0, num, den;
    
    printf("X\tY\n");
    for (i = 0; i < n; i++)
        scanf("%f%f", &x[i], &y[i]);
    
    printf("Enter the value of x for which y is to be found: ");
    scanf("%f", &X);
    
    for (i = 0; i < n; i++)
    {
        num = 1, den = 1;
        for (j = 0; j < n; j++)
        {
            if (j != i)
                num *= X - x[j], den *= x[i] - x[j];
        }
        Y += (num / den) * y[i];
    }
    
    printf("\nf(%.1f) = %.5f", X, Y);
    return 0;
}