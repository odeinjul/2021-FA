#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(abs(n)>1000000){
        cout<<"Out of bound: [-1000000, 1000000]"<<endl;
        cout<<"Please re-enter n:"<<endl;
        cin>>n;
    }
    if(n%15 == 0){
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    return 0;
}