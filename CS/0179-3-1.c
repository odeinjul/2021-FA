#include <stdio.h>
int main(){
    unsigned int i,n=100;
    unsigned int t=1;
    float f_pi=2.0,f_i=1.0;
    double d_pi=2.0,d_i=1.0;
    long double ld_pi=2.0,ld_i=1.0;
    printf("Enter the number of iteration:(0~4294967295)\n");
    scanf("%u",&n);
    printf("1-float, 2-double, 3-long double:\n");
    scanf("%u",&t);
    for(i=1;i<=n;i++){
        switch(t)
        {
            case 1:
                f_pi*=4.0*f_i*f_i/(2*f_i-1)/(2*f_i+1);//float
                f_i+=1.0;
                break;
            case 2:
                d_pi*=4.0*d_i*d_i/(2*d_i-1)/(2*d_i+1);//double
                d_i+=1.0;
                break;
            case 3:
                ld_pi*=4.0*ld_i*ld_i/(2*ld_i-1)/(2*ld_i+1);//long double
                ld_i+=1.0;
                break;
        }
    }
    switch(t){
        case 1:
            printf("After %u times of iteration, the value of (float)pi : %.10f\n",n,f_pi);
            break;
        case 2:
            printf("After %u times of iteration, the value of (float)pi : %.20f\n",n,d_pi);
            break;
        case 3:
            printf("After %u times of iteration, the value of (float)pi : %.20Lf\n",n,ld_pi);
            break;
    }
    return 0;
}