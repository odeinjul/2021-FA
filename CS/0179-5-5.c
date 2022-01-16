#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double nums[30];
int com(const void*a, const void*b){ //compare function for sort
    double temp = (*(double*)a-*(double*)b);
    if(temp >0) return 1;
    else if(temp<0)return -1;
    return 0;
}
void generate(){ //generate random number
    time_t t;
    srand((unsigned int)time(&t));
    for(int i = 0; i < 20;i++){
        nums[i] = rand() * rand() / (3.0*rand()) ;
    }
}
double average(){ // caculate the average 
    double sum;
    for(int i = 0; i < 20;i++){
        sum += nums[i];
    }
    return sum/20.0;
}
void find(double avg){ //find the closet number to the AVG is 
    int flag = 0;
    for(int i = 0; i < 20; i++){
        if(nums[i] >= avg && flag == 0){
            printf("The closet number to the AVG is :%lf\n",nums[i-1]);
            flag = 1;
        }
        printf("i: %d, nums[i]: %lf\n",i, nums[i]);
    }
    return ;
}
int main(){
    char ch,temp;
    ch=getchar();
    while(ch!='Q'&&ch!='q'){
        //printf("ch:%c\n",ch);
        generate();
        qsort(nums,20,sizeof(double),com); //sort 
        double avg = average();
        printf("The AVG is :%lf\n",avg);
        find(avg);
        ch = getchar();
        temp = getchar();
    }
    return 0;
}