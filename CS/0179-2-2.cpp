#include <iostream>
using namespace std;
int main(){
    int x,y;
    cin>>x>>y;
    if(abs(x)<=2 && abs(y)<=2){
        cout<<"Yes"<<endl;
        return 0;
    }
    cout<<"No"<<endl;
    return 0;
}