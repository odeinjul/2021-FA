#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d", &n);
    while(abs(n)>1000000){
        printf("Out of bound: [-1000000, 1000000]\n");
        printf("Please re-enter n:\n");
        scanf("%d", &n);
    }
    if(n%15 == 0){     // 3 | x, 5 | x -> [3,5] | x -> 15 | x
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}