#include <stdio.h>
int n,fi[50]={0,1,1};
int fib(int n){ //get nth fib and save it
    if(n==0)return 0;
    if(n==1) return 1;
    if(fi[n-1]!=0){
        if(fi[n-2]!=0){ //if is caculated , use it
            fi[n] = fi[n-1]+fi[n-2]; //save it
            return fi[n];
        }
        else{
            fi[n] = fi[n-1]+fib(n-2);
            return fi[n];
        }
    }
    else if(fi[n-2]!=0){
        fi[n] = fi[n-2]+fib(n-1);
        return fi[n];
    }
    else{
        fi[n]=fib(n-1)+fib(n-2);
        return fi[n];
    }
}
int main(){
    printf("Please enter n to get the nth of fib[]:\n"); //input
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("%d ", fib(i));
    }
    printf("\n");
    return 0;   
}