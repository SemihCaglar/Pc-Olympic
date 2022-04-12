#include<semih/competitive.h>

const int N=3005;
int n,m;
set<int> mark;
vi g[N];
bool vis[N];

void dfs(int node){
    if(vis[node] or mark.count(node)==0)
        return;
    vis[node]=true;
    for(auto i: g[node])
        dfs(i);
}

int main(){
    fast;
    test("closing");

    cin>>n>>m;    
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for(int i=1;i<=n;++i)
        mark.insert(i);

    for(int i=0;i<n;++i){
        dfs(*mark.begin());
        bool flag=true;
        for(int j=1;j<=n;++j)
            if(mark.count(j) and vis[j]==false)
                flag=false;
        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";

        int gg;
        cin>>gg;
        mark.erase(gg);
        memset(vis,0,sizeof(vis));
    }

    return 0;
}