#include<iostream>
#include<vector>
using namespace std;

int N;
string s;
int okyo,ech;

int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        okyo=1<<30;
        ech=1<<31;
        cin>>s;
        int n=s.size();
        bool flag=false;
        for (int i=0; i<n-2; i++){
            if (s[i]=='e' && s[i+1]=='c' && s[i+2]=='h'){
                ech=i;
            }
            if(i<n-3 && s[i]=='o' && s[i+1]=='k' && s[i+2]=='y' && s[i+3]=='o' && !flag){
                okyo=i;
                flag=true;
            }
        }
        if(okyo<ech){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        //cout<<okyo<<" "<<ech<<endl;
    }
    return 0;
}