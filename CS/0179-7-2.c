#include <stdio.h>
#include <stdlib.h>
char s[100];
int cnt = 0,c=0;
int check(char *s){
    while((*s) != '\0'){
        c++;
        //printf("c:%d\n",c);
        //printf("%c \n", (*s));
        if((*s) == '('){
            cnt ++;
        }
        else if((*s) == ')'){
            cnt --;
            if(cnt < 0){
                return -1;
            }
        }
        s++;
    }
    if(cnt >0)
        return -1;
    return 0;
}
int main(){
    while(1){
        cnt = 0;
        printf("Please enter the string.(Start with '#' to exit)\n");
        scanf("%s", s);
        if(s[0]=='#')
            return 0;
        if(check(s) == -1){
            printf("False.\n");
        }
        else{
            printf("True.\n");
        }
    }
    return 0;
}