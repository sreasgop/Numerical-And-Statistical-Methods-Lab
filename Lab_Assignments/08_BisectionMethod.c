#include<stdio.h>
#include<math.h>
float f(float x){
return (pow(10,x)+x-4);
}
int main(){
float a[100],b[100],x[100];
int n;
printf("Enter the values of a and b respectively:\n");
scanf("%f%f",&a[0],&b[0]);
x[0]=a[0];
n=0;
x[1]=(a[0]+b[0])/2;
if(f(a[0])*f(x[1])<0.0){
a[1]=a[0];
b[1]=x[1];
}
else{
a[1]=x[1];
b[1]=b[0];
}
while(fabs(x[n+1]-x[n])>0.00001){
n++;
x[n+1]=(a[n]+b[n])/2;
if(f(a[n])*f(x[n+1])<0.0){
a[n+1]=a[n];
b[n+1]=x[n+1];
}
else{
a[n+1]=x[n+1];
b[n+1]=b[n];
}
}
printf("\n The required root is %.4f",x[n+1]);
return 0;
}
