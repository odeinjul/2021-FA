#include <stdio.h>
int l[100],n;
int main(){
    printf("Please enter length of the array:\n"); //input
    scanf("%d\n",&n);
    while(n>100){
        printf("n in [1..100]:\n"); //input
        scanf("%d\n",&n);
    }
    int max0=0,j;
    for(int i=0;i<n;i++){
        scanf("%d",&l[i]);
        if(max0<l[i]){
            max0=l[i]; //get index of the max
            j=i;
        }
    }
    for(int i=j;i<n-1;i++){ //change position of J
        l[i]=l[i+1];
    }
    l[n-1]=max0;
    for(int i=0;i<n;i++){
        printf("%d ",l[i]); //output
    }
    return 0;   
}