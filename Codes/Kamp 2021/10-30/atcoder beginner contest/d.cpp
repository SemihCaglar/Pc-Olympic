#include<semih/competitive.h>

const int N=1e5+5;
int on[N],arka[N];
int n,q;

int main(){
    fast;
    // test();

    memset(on,-1,sizeof(on));
    memset(arka,-1,sizeof(arka));    
    cin>>n>>q;
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int x,y;
            cin>>x>>y;
            on[y]=x;
            arka[x]=y;
        }
        else if(op==2){
            int x,y;
            cin>>x>>y;
            on[y]=-1;
            arka[x]=-1;
        }
        else{
            int x;
            cin>>x;

            int cur=x;
            while(on[cur]!=-1)
                cur=on[cur];
            vi tmp;
            while(cur!=-1){
                tmp.pb(cur);
                cur=arka[cur];
            }
            cout<<tmp.size()<<" ";
            for(auto i:tmp)
                cout<<i<<" ";
            cout<<"\n";
        }
    }

    return 0;
}