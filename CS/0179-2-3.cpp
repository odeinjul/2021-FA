#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int n1=0;
    float n2=0;
    /* integer */
    printf("Please enter an integer in [0, 30):\n");
    scanf("%d", &n1);
    int t_n = n1/10;
    while(n1>=30||n1<=0){
        printf("Please enter an integer in [0, 30):\n");
        scanf("%d", &n1);
    }
    printf("x = %d, y = ",n1);
    switch(t_n){
        case 0:
            printf("%d\n",n1);
        
        case 1:
            printf("%d\n",n1*n1+1);
        
        case 2:
            printf("%d\n",n1*n1*n1+n1*n1+1);
        default:
            ;
    }
    /*float*/
    printf("Please enter an float in [0, 30):\n");
    scanf("%f", &n2);
    while(n2>=30||n2<=0){
        printf("Please enter an float in [0, 30):\n");
        scanf("%f", &n2);
    }
    printf("x = %f, y = ",n2);
    if(n2<10){
        printf("%f\n",n2);
    }
    else if(n2<20){
        printf("%f\n",n2*n2+1);
    }
    else{
        printf("%f\n",n2*n2*n2+n2*n2+1);
    }
    return 0;
}