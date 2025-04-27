// QUESTION:
/* Write a C program to solve the following system of linear equations
 correct to 4 decimal places by Gauss-elimination method:
 12.214 x_1 + 2.367 x_2 + 3.672 x_3 = 7.814
 2.412 x_1 + 9.879 x_2 + 1.564 x_3 = 4.890
 1.876 x_1 + 2.985 x_2 - 11.620 x_3 = -0.972
 File created by : Dr. Suddhyashil Sarkar
*/



// CODE:
#include<stdio.h>
int main(){
    int i,j,k,n;
    printf("Enter number of unknowns: ");
    scanf("%d",&n);
    float a[n+1][n+2], x[n], ratio;
    printf("\nEnter the elements of the augemented matrix:\n");
    
    for(i=1;i<=n;i++){
        for(j=1;j<=n+1;j++){
            printf("a[%d][%d] = ",i,j);
            scanf("%f",&a[i][j]);
        }
    }

    /* Applying Gauss Elimination */
    for(i=1;i<=n-1;i++){
        for(j=i+1;j<=n;j++){
            ratio = a[j][i]/a[i][i];
            for(k=1;k<=n+1;k++)
                a[j][k] = a[j][k] - ratio*a[i][k];
        }
    }

    /* Obtaining Solution by Back Subsitution */
    x[n] = a[n][n+1]/a[n][n];
    for(i=n-1;i>=1;i--){
        x[i] = a[i][n+1];
        for(j=i+1;j<=n;j++)
            x[i] = x[i] - a[i][j]*x[j];
        x[i] = x[i]/a[i][i];
    }

    /* Displaying Solution */
    printf("\nSolution:\n");
    for(i=1;i<=n;i++)
        printf("x[%d] = %.4f\n",i, x[i]);
    
    return(0);
}



// OUTPUT:
// Enter number of unknowns: 3
//
// Enter the elements of the augemented matrix:
// a[1][1] = 12.214
// a[1][2] = 2.367
// a[1][3] = 3.672
// a[1][4] = 7.814
// a[2][1] = 2.412
// a[2][2] = 9.879
// a[2][3] = 1.564
// a[2][4] = 4.890
// a[3][1] = 1.876
// a[3][2] = 2.985
// a[3][3] = -11.620
// a[3][4] = -0.972
//
// Solution:
// x[1] = 0.5000
// x[2] = 0.3333
// x[3] = 0.2500
