#include <stdio.h>
int main(){
    int i,j;
    for(i=1;i<=9;i++){
        for(j=1;j<=i;j++){
            printf("%d * %d = %d    ",j,i,i*j); //print each expr of the table
        }
        printf("\n"); //print out \n
    }
    return 0;   
}