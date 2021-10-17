#include<semih/competitive.h>

const int N=1e5+5;
int t,n,m;
vi v[N];
set<int> st;
bool vis[N];
set<pair<int,int>> edges;

void dfs(int node){
    if(vis[node]==true)
        return;
    vis[node]=true;
    st.erase(node);
    for(auto i: v[node]){
        if(vis[i]==false){
            edges.insert({min(i,node),max(i,node)});
            st.erase(i);
            dfs(i);
        }
    }
    while(!st.empty()){
        int next=*st.begin();
        edges.insert({min(next,node),max(next,node)});
        st.erase(next);
        dfs(next);
    }
}

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            st.insert(i);
        for(int i=0;i<m;++i){
            int x,y,z;
            cin>>x>>y>>z;
            v[x].pb(z);
            v[z].pb(x);
        }
        dfs(1);
        for(auto i:edges)
            cout<<i.fi<<" "<<i.se<<"\n";
        for(int i=0;i<=n;++i){
            vis[i]=false;
            v[i].clear();
        }
        edges.clear();
        st.clear();
    }    

    return 0;
}