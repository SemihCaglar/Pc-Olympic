#include<semih/competitive.h>

const int N=1e3+5;
int n;
ii a[N];
int ans;

void dfs(int node,bool *vis, vi *v){
    if(vis[node])
        return;
    vis[node]=true;
    for(auto i: v[node])
        dfs(i,vis,v);
}

bool check(int cost){
    vi v[N];
    bool vis[N];
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j){
            if(i==j)
                continue;
            int yatay=abs(a[i].fi-a[j].fi),dikey=abs(a[i].se-a[j].se);
            if(cost>=yatay*yatay+dikey*dikey)
                v[i].pb(j);
                v[j].pb(j);
        }
    dfs(1,vis,v);
    for(int i=0;i<n;++i)
        if(vis[i]==false)
            return false;
    return true;
}

int main(){
    fast;
    test("moocast");

    cin>>n;
    for(int i=0;i<n;++i){
        int x,y;
        cin>>x>>y;
        a[i]={x,y};
    }    
    int l=1,r=1e9;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid))
            ans=mid,r=mid;
        else
            l=mid+1;
    }
    cout<<ans<<"\n";

    return 0;
}