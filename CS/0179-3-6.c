#include <stdio.h>
int n;
int s1,s2;
float s3;
int main(){
    printf("Please enter n to get the nth list:\n"); //input
    scanf("%d",&n);
    float i = 1.0;
    for(float i=1.0;i<=n;i+=1.0){
        s1+=i;
        s2+=2*i-1;
        if(((int)i)%2==1)
            s3+=1.0/i;
        else
            s3-=1.0/i;
    }
    i=1.0;
    printf("for: s1:%d, s2:%d, s3:%f\n",s1,s2,s3);//for
    s1=s2=s3=0;
    while(i<=n){
        s1+=i;
        s2+=2*i-1;
        if(((int)i)%2==1)
            s3+=1.0/i;
        else
            s3-=1.0/i;
        i+=1.0;
    }
    printf("while: s1:%d, s2:%d, s3:%f\n",s1,s2,s3);//while
    s1=s2=s3=0;
    i=1.0;
    do{
        s1+=i;
        s2+=2*i-1;
        if(((int)i)%2==1)
            s3+=1.0/i;
        else
            s3-=1.0/i;
        i+=1.0;
    }while(i<=n);
    printf("do-while: s1:%d, s2:%d, s3:%f\n",s1,s2,s3);//do-while
    s1=s2=s3=0;
    printf("\n");
    return 0;   
}