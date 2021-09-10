#include<bits/stdc++.h>
using namespace std;

int t,n;
int a[(int)2e5+5];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;++i){
            int x;
            cin>>x;
            if(a[x]==0){
                a[x]=i;
            }
            else
            {
                a[x]=-1;
            }
            
        }
        bool flag=false;
        for(int i=1;i<=n;++i)
            if(a[i]>0){
                cout<<a[i]<<'\n';
                flag=true;
                break;
            }
        if(flag==false)
            cout<<"-1\n";
    }
}