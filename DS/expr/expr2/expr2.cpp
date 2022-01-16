// EXPR - 2   |  2021.10.18
// Tree

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

// DEFINATIONS
typedef char valType;
typedef struct Node{
    bool rtag, ltag, visited;
    struct Node *lchild, *rchild , *parent;
    valType data;
}Tree;
Node *pre, *savepre, *root;
// DEFINATIONS

// FUNCTIONS
Node* InitTree();
Node* CreateTree(); //For expressions
//Node* CreateTreeBasic(); //For trees
void PrintTree(Tree *T, int cnt);
void Preorder(Tree *T);
void PostorderInit();
void PostorderThreading(Tree *T);
void PostorderonThreading(Tree *T);
int Calculate(Tree *T);
// FUNCTIONS
// CreateTree() ->         A B # D G # # # C E # H # # F # #
//     + - 4 3 * 3 4

// MAIN
int main(){
    root = CreateTree(); 
    PostorderInit();     
    PostorderThreading(root);
    cout<<"---------------"<<endl;
    cout<<"Simply print out the tree (0 - subtrees, 1 - threads) :"<<endl;  
    PrintTree(root, 0);    
    cout<<"---------------"<<endl;
    pre = savepre;
    cout<<"Postorder of the tree (using threads) :"<<endl;  
    PostorderonThreading(pre);
    cout<<endl;
    cout<<"---------------"<<endl;
    cout<<"The result of the expression :"<<endl;
    cout<<Calculate(root)<<endl;
    cout<<"---------------"<<endl;
    return 0;
}
// MAIN

// FUNCTIONS
Node* InitTree(){ //Q1
    Node *root = (Node *)malloc(sizeof(Node));
    root -> data = 0;
    root -> lchild = NULL;
    root -> rchild = NULL;
    return root;
}

/*Node* CreateTreeBasic(){ //Q2 
    Node *now = (Node *)malloc(sizeof(Node));
    char t;
    cin>>t;
    if(t=='#'){
        now = NULL;
        //cout<<"#"<<endl;
        return now;
    }
    else{
        now -> data = t;
        now -> lchild = CreateTree();
        if(now -> lchild == NULL)
            now -> ltag = 1;
        else{
            now -> lchild -> parent = now;
            now -> ltag = 0;
        }
        now -> rchild = CreateTree();
        if(now -> rchild == NULL)
            now -> rtag = 1;
        else{
            now -> rchild -> parent = now;
            now -> rtag = 0;
        }
        //cout<<(now -> data)<<endl;
        return now;
    }
}*/

Node* CreateTree(){ //Q2 -> Q6C
    Node *now = (Node *)malloc(sizeof(Node));
    char t;
    cin>>t;
    if(t=='#'){
        now = NULL;
        //cout<<"#"<<endl;
        return now;
    }
    else{
        now -> data = t;
        if('0' <= t && t <= '9'){
            now -> lchild = NULL;
        }
        else{
            now -> lchild = CreateTree();
        }
        if(now -> lchild == NULL)
            now -> ltag = 1;
        else{
            now -> lchild -> parent = now;
            now -> ltag = 0;
        }
        if('0' <= t && t <= '9'){
            now -> rchild = NULL;
        }
        else{
            now -> rchild = CreateTree();
        }
        if(now -> rchild == NULL)
            now -> rtag = 1;
        else{
            now -> rchild -> parent = now;
            now -> rtag = 0;
        }
        //cout<<(now -> data)<<endl;
        return now;
    }
}

void PrintTree(Tree *T,int cnt){ 
    for(int i = cnt; i >= 0; i--)
        cout<<"    ";
    if(T == NULL){
        cout<<"#"<<endl;
        return ;
    }
    cout<<(T -> data)<<'('<<(T -> ltag)<<','<<(T -> rtag)<<')'<<endl;
    if(T -> ltag == 1){
        for(int i = cnt+1; i >= 0; i--)
            cout<<"    ";
        if(T -> lchild == T) {
            cout<<"START"<<endl;
        }
        else{
            cout<<(T -> lchild -> data)<<endl;
        }
    }
    else{
        PrintTree(T -> lchild, cnt + 1);
    }

    if(T -> rtag == 1){
        for(int i = cnt+1; i >= 0; i--)
            cout<<"    ";
        cout<<(T -> rchild -> data)<<endl;
    }
    else{
        PrintTree(T -> rchild, cnt + 1);
    }
    return;
}

void Preorder(Tree *T){ //Q3
    if(T == NULL){
        cout<<"#";
    }
    else{
        cout<<(T -> data);
        Preorder(T -> lchild);
        Preorder(T -> rchild);
    }
    return ;
}

void PostorderInit(){
    pre = root;
    while(pre -> lchild != NULL || pre -> rchild != NULL){
        while(pre -> lchild != NULL) pre = pre -> lchild;
        if(pre -> rchild != NULL) pre = pre -> rchild;
    }
    savepre = pre;
}

void PostorderThreading(Tree *T){ //Q4
    if(T != NULL){
        PostorderThreading(T -> lchild);
        PostorderThreading(T -> rchild);
        if(T -> ltag == 1){
            T -> lchild = pre;
        }
        if(pre -> rtag == 1){
            pre -> rchild = T;
        }
        pre = T;
    }
}

void PostorderonThreading(Tree *T){ //Q5 -> Q7
    while(T -> rtag == 1 && T -> rchild -> visited == 0){
        cout<<(T -> data)<<' ';
        T -> visited = 1;
        T = T -> rchild;
    }
    T -> visited = 1;
    if(T -> ltag == 0 && T -> lchild -> visited == 0){
        PostorderonThreading(T -> lchild);
    }
    if(T -> rtag == 0 && T -> rchild -> visited == 0){
        PostorderonThreading(T -> rchild);
    }
    cout<<(T -> data)<<' ';
    if(T == root){
        return;
    }
    if(T -> parent -> visited == 0){
        PostorderonThreading(T -> parent);
    }
}

int Calculate(Tree *T){ //Q8A
    if(T -> data == '+'){
        return Calculate(T -> lchild) + Calculate(T -> rchild);
    }
    else if(T -> data == '-'){
        return Calculate(T -> lchild) - Calculate(T -> rchild);
    }
    else if(T -> data == '*'){
        return Calculate(T -> lchild) * Calculate(T -> rchild);
    }
    else if(T -> data == '/'){
        return Calculate(T -> lchild) / Calculate(T -> rchild);
    }
    else if('0' <= T -> data && T -> data <= '9'){
        return (T->data) - '0';
    }
    return 0;
}
// FUNCTIONS