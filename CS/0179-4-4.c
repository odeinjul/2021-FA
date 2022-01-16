#include <stdio.h>
float x;
int i,money,cnt[10],change[10]={1000,500,200,100,50,10,5,1};
int main(){
    printf("Please enter the mount of money (x.xx yuan) :"); //input
    scanf("%f",&x); //input
    x*=10.0;
    money = (int)(1000-x+0.5); //transform
    for(i=0;i<=7;i++){
        cnt[i]=money / change[i];
        money %= change[i];
    }
    printf("Changed %.1lf yuan ,",(float)((int)(1000-x+0.5)/10.0)); //output
    for(i=0;i<=7;i++){
        printf("%.2lf yuan * %d \n",(float)change[i]/10,cnt[i]);
    }

}