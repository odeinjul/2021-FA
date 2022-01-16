#include <stdio.h>
int cnt; //global varible - static and can be accessed by every function
int get_2x(int a){
    static int self_cnt = 0; //static local varible - can only be accessed by this function but won't be redefined each time
    self_cnt++;
    cnt++;
    printf("input of func(get_2x): %d\n", a);
    printf("Times func(get_2x) is called: %d\n", self_cnt);
    printf("output of func(get_2x): %d\n", 2*a);
    return 2*a;
}
int get_3x(int a){ //a - formal parameter - only are names to identify the varible in this function, need to be past value.
    int x = 3;
    cnt ++;
    return x*a;
}
int main(){
    int temp;
    scanf("%d",&temp); //input
    temp = get_2x(temp);
    temp = get_3x(temp);
    temp = get_2x(temp);
    temp = get_3x(temp);
    temp = get_2x(temp);// temp = temp * 2 * 3 * 2 * 3 *2
    //self_cnt - count how many times get_2x() is called
    //cnt - count how many times all functions(except main) are called
    printf("Times all functions are called: %d\n", cnt);
    printf("output(= 72 * input): %d\n",temp);//check
    return 0;
}