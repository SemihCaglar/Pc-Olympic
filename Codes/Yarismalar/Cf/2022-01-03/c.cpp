#include<semih/competitive.h>

const int N=1e4+5;
int t,n;
int ans[N];
bool vis[N];

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>n;
        int cnt=0;
        for(int i=1;i<=n;++i){ // soracagimiz ind.
            if(vis[i])
                continue;
            int prev;
            cout<<"? "<<i<<"\n"<<flush;
            cin>>prev;
            int yanit;

            while(true){
                if(vis[prev] or cnt==n)
                    break;
                cout<<"? "<<i<<"\n"<<flush;
                cin>>yanit;
                ans[prev]=yanit;
                vis[prev]=true;
                prev=yanit;
                cnt++;
            }
            if(cnt==n){
                cout<<"! ";
                for(int j=1;j<=n;++j)
                    cout<<ans[j]<<" ";
                cout<<"\n"<<flush;
                for(int j=0;j<=n;++j)
                    vis[j]=false;
                break;
            }
        }
    }    

    return 0;
}