#include<iostream>
using namespace std;

int n;
int a[100001],b[100000];
long long int ans;

int main(){
    cin>>n;
    for (int i=0; i<n+1; i++){
        scanf("%d",&a[i]);
    }
    int temp=0;
    ans=0;
    for (int i=0; i<n; i++){
        scanf("%d", &b[i]);
        ans+=min(temp,a[i]);
        a[i]-=temp;
        a[i]=max(a[i],0);
        ans+=min(a[i],b[i]);
        temp=max(0, b[i]-a[i]);
        //cout<<i<<" : "<<temp<<" : "<<ans<<endl;
    }
    ans+=min(temp,a[n]);
    //cout<<min(temp,a[n]);
    cout<<ans<<endl;
    return 0;
}