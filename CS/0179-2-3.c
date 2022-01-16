#include <stdio.h>
#include <stdlib.h>
int main(){
    int x,y;
    scanf("%d%d",&x, &y); //input
    if(abs(x)<=2 && abs(y)<=2){ //check     |x|<=2 && |y|<=2 -> (x,y) in the square
        printf("YES"); //output1
        return 0;
    }
    printf("NO");//output2
    return 0;
}