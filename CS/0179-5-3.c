#include <stdio.h>
int gcd(int,int); //define gcd
int lcm(int m,int n); //define lcm
int main(){
    int num1,num2; 
    scanf("%d %d",&num1,&num2); //input
    printf("gcd(num1,num2)=%d\nlcm(num1,num2)=%d\n",gcd(num1,num2),lcm(num1,num2)); //output
    return 0;
}
int gcd(int m, int n){ //body of gcd
    if(n == 0)  
        return m;
    else    
        return gcd(n,m%n);
}
int lcm(int m, int n){ //body of lcm
    return n*m/gcd(m,n);
}