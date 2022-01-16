#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "0179-8-2.c"
typedef struct words{
    char w[30];
    int num;
    struct words *next;
} word;
word *head, *p;
FILE *fp;
void read(word *head);
void sort(word *head);

int main(){
    word *head = (word *)malloc(sizeof(word));
    head -> next = NULL;
    fp = fopen(FILE_NAME, "r"); //open
    if(fp == NULL){
        printf("Can't open file: %s.\n", FILE_NAME);
        exit(EXIT_FAILURE);
    }
    printf("START READING FILE\n");
    read(head);
    printf("START SORTING WORDS\n");
    sort(head);
    fclose (fp);
    return 0;
}

void read(word *head){ //read text & save
    char ch;
    char temp[30];
    int i = 0;
    temp[0] = '#';
    while(!feof(fp)){
        ch = fgetc(fp);
        i = 0;
        while((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || temp[0] == '#'){
            if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
                temp [i] = ch;
                i++;
            }
            ch = fgetc(fp);
            if(feof(fp))break;
        }
        temp[i] = '\0';
        word *p;
        p = head -> next;
        while(p){
            if(!strcmp(temp, p -> w)){
                p -> num++;
                break;
            }
            p = p -> next;
        }
        if(!p && temp[0] != '\0'){
            word *p = (word *)malloc(sizeof(word));
            strcpy(p -> w, temp);
            p -> num = 1;
            p -> next = head -> next;
            head -> next = p;
        }
    }

}

void sort(word *head){ //find top 10 words
    word *p;
    int i;
    int a[10] = {0};
    printf("TOP 10:\n");
    for(i = 0; i < 10; i++){
        p = head;
        while(p != NULL){
            if(p -> num > a[i]){
                a[i] = p -> num;
            }
            else{
                p = p -> next;
            }
        }
        p = head;
        while(p != NULL){
            if(a[i] == p -> num){
                p -> num = 0;
                printf("No.%d: %d times\n", i, a[i]);
                puts(p -> w);
                break;
            }
            else{
                p = p -> next;
            }
        }
    }
}