#include<semih/competitive.h>

const int N=3e5+5;
vii g[N];
int n,k,d;
bool vis[N];
bool police[N];
set<int> ans;

int main(){
    fast;
    // test();

    cin>>n>>k>>d;    
    queue<ii> q;
    for(int i=0;i<k;++i){
        int x;
        cin>>x;
        q.push({x,-1});
        police[x]=true;        
    }
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        g[u].pb({v,i});
        g[v].pb({u,i});
    }
    while(!q.empty()){
        int node=q.front().fi;
        int dad=q.front().se;
        q.pop();
        if(vis[node])
            continue;
        vis[node]=true;
        for(auto i: g[node]){
            if(i.fi==dad)
                continue;
            if(vis[i.fi] or police[i.fi])
                ans.insert(i.se);
            else
                q.push({i.fi,node});
        }
    }
    cout<<ans.size()<<"\n";
    for(auto i:ans)
        cout<<i<<" ";
        
    return 0;
}