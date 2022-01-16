#include <stdio.h>
int gcd(int a,int b){ //return gcd of a,b
    if(b == 0)  
        return a;
    else    
        return gcd(b,a%b);
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);//input
    int c = gcd(a,b);
    a /= c; //divide by the gcd of a,b
    b /= c;
    printf("%d/%d\n",a,b); //output
    return 0;
}