#include<semih/competitive.h>

const int N=1e5+5;
int n,m;
ii a[N];
vi v[N];
int max_x,min_x,max_y,min_y;
bool vis[N];
int ans=INT_MAX;

void dfs(int node){
    if(vis[node])
        return;
    vis[node]=true;

    max_x=max(max_x,a[node].fi);
    min_x=min(min_x,a[node].fi);
    max_y=max(max_y,a[node].se);
    min_y=min(min_y,a[node].se);

    for(auto i: v[node])
        dfs(i);
}

int main(){
    fast;
    test("fenceplan");

    cin>>n>>m;
    for(int i=0;i<n;++i){
        int x,y;
        cin>>x>>y;
        a[i]={x,y};
    }    
    for(int i=0;i<m;++i){
        int x,y;
        cin>>x>>y;
        x--,y--;
        v[x].pb(y);
        v[y].pb(x);
    }
    for(int i=0;i<n;++i){
        if(vis[i]==false){
            max_x=max_y=-1, min_x=min_y=INT_MAX;
            dfs(i);
            ans=min(ans, (max_x-min_x+max_y-min_y)*2 );
        }
    }

    cout<<ans<<"\n";

    return 0;
}