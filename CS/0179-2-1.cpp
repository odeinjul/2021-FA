#include <stdio.h>
#include <stdlib.h>
int a,b,c;
float x,y;
void work(int a,int b, int c,float x, float y){
    int a0 = a, b0 = b, c0 = c, x0 = x, y0 = y;
    /*part 1*/
    printf("3.5+1/2+56%10 = %d\n",(3.5+1/2+56%10));//9.5
    printf("a++*1/3 = %d\n",(a++*1/3));//0
    printf("x+a%3*(int)(x+y)%2/4 = %d\n",(x+a%3*(int)(x+y)%2/4));//3.5
    a=a0;
    printf("(float)(a+b)/2+(int)x%(int)y = %d\n\n",((float)(a+b)/2+(int)x%(int)y));//5.5
    
    printf("b>c&&b==c = %d\n",(b>c&&b==c)); //0
    printf("!(a>b)&&!c||1 = %d\n",(!(a>b)&&!c||1)); //0
    printf("!(x=a)&&(y=b)&&0 = %d\n",(!(x=a)&&(y=b)&&0)); //1
    x = x0; y = y0;
    printf("!(a+b)+c-1&&b+c/2 = %d\n",(!(a+b)+c-1&&b+c/2)); //0
    printf("!1&&30%10>=0&&30%10<=3 = %d\n\n",(1&&30%10>=0&&30%10<=3)); //1

    //todo
    a+=a+b;
    printf("a+=a+b = %d\n",a);//7
    a = a0;

    a*=b%c;
    printf("a*=b%c = %d\n",a);//6
    a = a0;

    a/=c-a;
    printf("a/=c-a = %d\n",a);//1
    a = a0;

    a+=a-=a*=a;
    printf("a+=a-=a*=a, a = %d\n",a);//0
    a = a0;
    b = b0;

    a=(a=++b,a+5,a/5);
    printf("a=(a=++b,a+5,a/5), a = %d, b = %d\n",a,b); //0 4
    b = b0; a = a0;

    printf("(a>=b>=2)?1:0 = %d\n",((a>=b>=2)?1:0));
    a = a0;
}
int main(){
    /*input*/
    a=2;b=3;c=4;x=3.5;y=4.8;
    work(a,b,c,x,y);
    scanf("%d%d%d",&a,&b,&c); //2 3 4
    printf("%f%f",&x,&y);//3.5 4.8
    work(a,b,c,x,y);
}