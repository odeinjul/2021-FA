#include <stdio.h>
#include <ctype.h>
int getInput(char c){
    return isalpha(c);
}
int main(){
    int words = 0, state = 0, input = 0;
    //words - count of words
    //state - 0 1 - state of word
    //input - 0 1 - state of input
    char ch;
    while((ch = getchar())!='#'){
        input = getInput(ch); //check the character is in alphabet or is space
        if(state == 0 && input ==0){ //change the state
            state = 0;
        }
        else if(state == 0 && input ==1){
            state = 1;
            words ++;
        }
        else if(state == 1 && input ==1){
            state = 1;
        }
        else{
            state = 0;
        }
    }
    printf("The number of words is :%d\n",words); //output
    return 0;
}