// EXPR - 1   |  2021.9.24
// Package
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef struct monos{
    int weight;
    bool storaged;
}valType;

//---STACK START---
#define STACK_INIT_SIZE = 100;
#define STACK_INCRECEMENT_SIZE = 10;
typedef struct Node {
    valType data;
    struct Node *next;
} StackNode,*LinkStart;
typedef struct MyStack{
    LinkStart top;
    int count;
}myStack;

void InitStack (myStack *s);
int Push(myStack *s, valType e);
int StackLength (myStack *s);
bool StackEmpty (myStack *s);
void PrintStack(myStack *s);
void work(int T, myStack *s,int now);
valType Top(myStack *s);
valType Pop(myStack *s);
//---STACK END---

valType mono[1000];
int T,n,i = 0;
int main(int argc, char *argv[]){
    freopen(argv[1],"r",stdin);
    freopen(argv[2],"w",stdout);
    myStack s;
    InitStack(&s);
    cin>>T>>n;
    //printf("%d %d",T,n);
    for(i = 0; i < n; i++){
        cin>>mono[i].weight;
        mono[i].storaged = 0;
    }
    work(T, &s, 0);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

//FUNCTIONS
void work(int T, myStack *s,int now){
    if(T == 0){
        PrintStack(s);
    }
    else{
        for(int i = now; i < n; i++){
            if(!mono[i].storaged && T >= mono[i].weight ){
                T -= mono[i].weight;
                mono[i].storaged = 1;
                Push(s, mono[i]);
                work(T, s, i+1);
                Pop(s);
                mono[i].storaged = 0;
                T += mono[i].weight;
            }
            else{
                continue;
            }
        }
    }
}

//---STACK START---
void InitStack(myStack *s){
    s->top = NULL;
    s->count = 0;
    return ; 
}

int StackLength(myStack *s){
    return s->count;
}

int Push(myStack *s, valType e){
    StackNode *p = (StackNode *)malloc(sizeof(valType));
    if(!p)  return -1;
    p->data = e;
    p->next = s->top;
    s->top = p;
    s->count++;
    return 0;
}

bool StackEmpty(myStack *s){
    return (!s->count);
}

valType Top(myStack *s){
    StackNode *p = s->top;
    valType e = p->data;
    return e;
}

void PrintStack(myStack *s){
    StackNode *tmp;
    tmp = s->top;
    while(tmp->next != NULL){
        cout<<tmp->data.weight<<' ';
        tmp = tmp->next;
    }
    cout<<tmp->data.weight<<endl;
}

valType Pop(myStack *s){
    StackNode *p = s->top;
    valType e = p->data;
    s->top = p->next;
    free(p);
    s->count--;
    return e;
}
//---STACK END---