#include <stdio.h>
#include <stdlib.h>
#include <time.h>
time_t t;
int seed,l,r,guess,red_bag;
int rand_num;
char ch='5'; 
int main(){
st:    printf("Please enter the seed of the rand_num : \n");
    scanf("%d",&seed);
    printf("Please enter the boundaries of the rand_num [-32767,32767]: \n"); 
    scanf("%d%d",&l,&r);     //input
    srand(seed);
    rand_num=rand()%(r-l)+l; //generate a rand_num
    printf("Please guess the rand num: \n");
    scanf("%d",&guess);
    while(guess!=rand_num){ //guess
        if(guess<rand_num){
            printf("Too small, please guess again : ");
            scanf("%d",&guess);
        }
        else if(guess>rand_num){
            printf("Too large, please guess again : ");
            scanf("%d",&guess);
        }
    }
    red_bag=((unsigned) time(&t)*rand_num)%198+2; //generate rad_bag
    printf("You win, the rand_num is : %d\nAnd you get a red bag of %d yuan.\n",rand_num,red_bag); //output
    ch = getchar();ch = getchar();
    if('0'>ch||ch>'9'){
        printf("Exited.\n");
        return 0;
    }
    goto st;
}