#include<semih/competitive.h>

const int N=2e5+5;

int t,n;
int ans[N];
bool vis[N];

int main(){
    fast;
    test();

    cin>>t;
    while (t--){
        cin>>n;
        forr(i,0,n+4)
            ans[i]=vis[i]=0;
        int sum=0,last=1;
        for(int i=1;i<=n;++i){
            int x;
            cin>>x;
            if(vis[x]==false){
                vis[x]=true;
                sum++;
                ans[i]=x;
            }
            else{
                for(;vis[last];last++);
                ans[i]=last;
                vis[last]=true;
            }
        }
        cout<<sum<<"\n";
        for(int i=1;i<=n;++i)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
        

    return 0;
}