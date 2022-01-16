#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)
float a,b,c;
int main(){
    scanf("%f%f%f",&a,&b,&c);
    printf("a : %f, b : %f, c : %f\n", a, b, c);
    //sort
    int a0 = max(a,max(b,c)),c0=min(a,min(b,c)),b0;
    if(a!=a0 && a!=c0) b0=a;
    if(b!=a0 && b!=c0) b0=b;
    if(c!=a0 && c!=c0) b0=c;

    //Check Triangle
    while(b0+c0<=a0){
        printf("Can;t form a triangle, please re-enter:\n");
        scanf("%f%f%f",&a,&b,&c);
        printf("a : %f, b : %f, c : %f\n", a, b, c);
        a0 = max(a,max(b,c)),c0=min(a,min(b,c));
        if(a!=a0 && a!=c0) b0=a;
        if(b!=a0 && b!=c0) b0=b;
        if(c!=a0 && c!=c0) b0=c;
    }

    //check equal
    if(a==b || b==c || a==c){
            if(a==b && b==c)
                printf("Equilateral triangle\n");
            else
                printf("Isosceles triangle\n");
    }
    else{
        printf("No sides are equal\n");
    }

    //check angle
    if(c0*c0+b0*b0==a0*a0){
        printf("Right-angled triangle\n");
    }
    else if(c0*c0+b0*b0>a0*a0){
        printf("Acute triangle\n");
    }
    else{
        printf("Obtuse triangle\n");
    }

    //Helen to evaluate the area of the triangle
    float s=0,p = (a+b+c)/2;
    s = sqrt(p*(p-a)*(p-b)*(p-c));
    printf("Area of the triangle: %f\n",s);
    return 0;
}