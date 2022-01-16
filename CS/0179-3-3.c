#include <stdio.h>
float inpu;
int a[100],b[100]={0};
int main(){
    printf("Please enter a float number: \n"); //input
    scanf("%f",&inpu);
    if(inpu<0)//abs(inpu)
    {
        printf("-");
        inpu=0-inpu;
    }
    float dec = inpu - (int)inpu;
    float dec1=dec;
    inpu -= dec;
    int inpu1 = (int) inpu;
    int cnt1=0,cnt2=0;
    //printf("%d\n",inpu1);
    //printf("%f\n",dec);
    while(inpu1!=0){//integral part 
        a[cnt1]=inpu1%2;
        inpu1/=2;
        cnt1++;
    }
    while(dec!=0&&cnt2<=99){ //decimal part 
        b[cnt2]=(dec*2)/1;
        if(dec*2>=1)
            dec = dec*2-1;
        else
            dec*=2;
        cnt2++;
    }
    for(int i=cnt1-1;i>=0;i--){ //integral part output
        printf("%d",a[i]);
    }
    if(dec1!=0){
        printf(".");
    for(int i=0;i<cnt2;i++){//decimal part input
        printf("%d",b[i]);
    }
    }
    if(cnt2==0)printf("0");
    printf("\n");
    return 0;
}