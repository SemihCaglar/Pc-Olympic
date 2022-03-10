#include<semih/competitive.h>

const int N=1e5+5;
const int MOD=1e9+7;
int n;
vi g[N];
ll dp[N][2];

ll f(int node, int dad, int color){ // 1: siyah
    ll &ref=dp[node][color];
    if(ref)
        return ref;
    ll carpi=1;
    for(auto to: g[node]){
        if(to==dad)
            continue;
        if(color==1)
            carpi*=f(to,node, 0), carpi%=MOD;
        else
            carpi*=f(to,node,0)+f(to,node,1)%MOD, carpi%=MOD;
    }
    return ref=carpi;
}

int main(){
    fast;
    // test();

    cin>>n;   
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    } 
    cout<<(f(1,-1,0)+f(1,-1,1))%MOD;

    return 0;
}