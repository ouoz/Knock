#include<iostream>
using namespace std;
 
int a,b;
 
int main(){
    cin>>a>>b;
    int x=min(a,b);
    int y=max(a,b);
    if((y-x)%2!=0){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<(y-x)/2+x<<endl;
    }
    return 0;
}