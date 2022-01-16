#include <stdio.h>
#include <math.h>
double f(double x){ //func f
    return 3*x*x*x-3*x*x+x-6;
}
double fd(double x){ //func f'
    return 9*x*x-6*x+1;
}
double d = 1e-6;
double x0,l,r,x1;
int cnt = 0;
int main(){

    //Newton's method
    printf("Please enter the start value of Newton's method :\n");
    scanf("%lf",&x0);
    while(fabs(x1-x0)>=d){
        x1=x0;
        x0 = x0 - f(x0)/fd(x0);
        cnt ++; //counter
    }
    printf("x = %lf, iteration times: %d\n",x0,cnt);

    //Binary's method
    printf("Please enter the boundary of Binary's method :\n");
    scanf("%lf%lf",&l,&r);
    cnt = 0;
    while((r-l)>=d){
        double mid = (l+r)/2.0;
        if(f(mid)<0){
            if(f(l)>0){
                r=mid;
            }
            else if(f(r)>0){
                l=mid;
            }
        }
        else if (f(mid)>0){
            if(f(l)<0){
                r = mid;
            }
            else if(f(r)<0){
                l=mid;
            }
        }
        cnt ++; //counter
    }
    printf("x = %.6lf, iteration times: %d\n",r,cnt);
}