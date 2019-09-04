#include<iostream>
using namespace std;

int n,x;
int a[500000];
int xsum=0;
int discnt=0;

int main(){
    cin>>n>>x;
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(a[i]==-1){
            discnt++;
            continue;
        }
        xsum=(xsum^a[i]);
        //cout<<xsum<<endl;
    }
    //cout<<xsum<<" "<<x<<endl;//////////
    bool msbflag;
    int temp1=xsum,temp2=x;
    int msb;
    bool flag1=false;
    for (int i=0; ;i++){
        //cout<<temp1<<" "<<temp2<<endl;
        if((temp1==0 || temp2==0 )&& !flag1){
            msbflag=temp1>temp2;
            flag1=true;
        }
        if(temp1==0 && temp2==0){
            msb=i;
            break;
        }
        temp1/=2;
        temp2/=2;
        //cout<<temp1<<" "<<temp2<<endl;
    }
    if (discnt==0){
        if(xsum==x){
            for (int i=0; i<n; i++){
                if(i!=0){
                    cout<<" ";
                }
                cout<<a[i];
            }
            cout<<endl;
        }
        else{
            cout<<-1<<endl;
        }
        return 0;
    }
    else if (msbflag){
        cout<<-1<<endl;
        return 0;
    }
    //cout<<"aaaa"<<endl;

    if ((xsum^x)>x){
        //cout<<"haitta"<<endl;
        if (discnt<=1){
            cout<<-1<<endl;
            return 0;
        }
        bool flag2=false,flag3=false;
        for (int i=0; i<n; i++){
            if (i!=0){
                cout<<" ";
            }
            if (a[i]==-1 && !flag2){
                if(msb==0){
                    cout<<0;
                }
                cout<<(1<<(msb-1));
                flag2=true;
                continue;
            }
            if(a[i]==-1 && flag2 && !flag3){
                if(msb==0){
                    cout<<0;
                }
                cout<<(xsum^x)-(1<<(msb-1));
                flag3=true;
                continue;
            }
            cout<<a[i];
        }
        return 0;
    }

    int ans=(xsum^x);
    bool flag=false;
    for (int i=0; i<n; i++){
        if (i!=0){
            cout<<" ";
        }
        if (a[i]==-1){
            if(!flag){
                cout<<ans;
                flag=true;
            }
            else{
                cout<<0;
            }
        }
        else{
            cout<<a[i];
        }
    }
    return 0;
}