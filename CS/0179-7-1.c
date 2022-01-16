#include <stdio.h>
#include <stdlib.h>
char input[200];
char* indexa;
int flag,maxn = 0,cnt = 0;
void check(char *s){
    do{
    //printf("%d\n",maxn);
        //printf("%d\n",cnt);
        if(flag == 0 && (*s) != ' '){
            flag = 1;
            cnt = 1;
        }
        else if (flag == 1 && (*s) != ' '){
            cnt ++;
        }
        else if(flag == 1 && ((*s) == ' ' || (*s)=='\0')){
            flag = 0;
            if(cnt > maxn){
                indexa = s;
                maxn = cnt;
            }
        }
        s++;
    }while((*s) != '\0');
    if(flag == 1){
        flag = 0;
            if(cnt > maxn){
                indexa = s;
                maxn = cnt;
            }
    }
    int i;
    for(i = 1; i <= maxn; i++){
                    indexa--;
    }
    printf("The longest word:\n");
    while((*indexa) != ' ' && (*indexa) != '\0'){
        printf("%c",*indexa);
        indexa++;
    }
    printf("\n");
    return ;
}
int main(){
    printf("Please input a string within 200 character.\n");
    gets(input);
    //printf("%s\n", input);
    check(input);
    return 0;
}