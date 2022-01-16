//kmp
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[1000100],b[1000100];
int p[1000100];
int main(){
    scanf("%s%s", a+1, b+1);
    int la=strlen(a+1),lb=strlen(b+1);
    int j=0;p[1]=0;
    for(int i = 2; i <= lb; i++){
        while(j != 0 && b[j+1] != b[i]) j=p[j];
        if(b[j+1] == b[i]) j++; 
        p[i]=j;
    }
    j=0;
    for(int i = 1; i <= la; i++){
        while(j != 0 && b[j+1] != a[i]) j=p[j];
        if(b[j+1] == a[i]) j++; 
        if(j==lb) cout<<i-lb+1<<endl;
    }
    for(int i = 1; i <= lb; i++){
        cout<<p[i]<<' ';
    }
    cout<<endl;
    return 0;
}