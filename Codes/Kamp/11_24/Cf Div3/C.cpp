#include<bits/stdc++.h>
using namespace std;

int t,n,tmp;
int ar[(int)2e5+5];

int num[(int)2e5+5];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<=n;++i)
            num[i]=-1;
        for(int i=0;i<n;++i)
            cin>>ar[i];
        
        tmp=ar[0];
        bool con=false;

        for(int i=1;i<n-1;++i){
            if(ar[i]!=ar[i-1]&&ar[i]!=ar[i+1]){
                num[ar[i]]++;
            }
        }    
        for(int i=0;i<n;++i){
            if(ar[i]!=tmp)
                con=true;
        }
        int mn=0x7fffffff;
        for(int i=1;i<=n;++i){
            if(num[i]!=-1)
                mn=min(mn,num[i]);
        }
        if(mn==0x7fffffff&&con==false)
            cout<<"0\n";
        else if(num[ar[0]]==-1||num[ar[n-1]]==-1)
            cout<<"1\n";
        else
            cout<<mn+2<<'\n';

    }
}