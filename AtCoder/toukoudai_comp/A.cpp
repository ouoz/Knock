#include<iostream>
using namespace std;

int a,b,t;

int main(){
    cin>>a>>b>>t;
    int x=b-a;
    while(1){
        b+=x;
        if(b>=t){
            break;
        }
    }

    cout<<b<<endl;

    return 0;
}