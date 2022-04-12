#include<semih/competitive.h>

const int N=205;
typedef pair<ii,int> iii;
int n;
iii a[N];
vi v[N];
bool vis[N];

void dfs(int node){
    if(vis[node])
        return;
    vis[node]=true;
    for(auto i: v[node])
        dfs(i);
}

int main(){
    fast;
    test("moocast");

    cin>>n;
    for(int i=0;i<n;++i){
        int x,y,z;
        cin>>x>>y>>z;
        a[i]={{x,y},z};
    }    
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j){
            if(j==i)
                continue;
            int yatay=abs(a[i].fi.fi-a[j].fi.fi),dikey=abs(a[i].fi.se-a[j].fi.se);
            if(a[i].se*a[i].se>=yatay*yatay+dikey*dikey)
                v[i].pb(j);
        }
    int ans=-1;
    for(int i=0;i<n;++i){
        memset(vis,0,sizeof(vis));
        dfs(i);
        int cnt=0;
        for(int i=0;i<n;++i)
            if(vis[i])
                cnt++;
        ans=max(ans,cnt);
    }
    cout<<ans<<"\n";

    return 0;
}