#include<semih/competitive.h>

const int N=2e5+5;
int n,m;
int k[N];
ll coin[N];

class kosaraju{
    public:    
    
    kosaraju(int graph_n,int graph_m){
        this->n=graph_n;
        this->m=graph_m;
        this->g.resize(n+1);
        this->transpose_g.resize(n+1);
        this->vis.resize(n+1);
        this->component_group.resize(n+1);
        this->component_number=0;
    }
    
    int n,m;                                                 // n: vertex, m:edge
    vector< vector<int> > g, transpose_g, component_g;
    vector<int> finish;                                      // decreasing order of their finish times
    vector<bool> vis;                                        // visited
    vector<int> component;
    vector<int> component_group;                             // kim kacinci grupta
    int component_number;

    void dfs1(int x){                                        // find the exit times
        vis[x]=true;
        for(auto i: g[x])
            if(vis[i]==false)
                dfs1(i);
        finish.pb(x);        
    }

    void dfs2(int x){                                        // find the strongly connected components
        vis[x]=true;
        for(auto i: transpose_g[x])
            if(vis[i]==false)
                dfs2(i);
        component.pb(x);
    }

    void make_component_graph(){

        vis.assign(n+1,false);
        for(int i=1;i<=n;++i)
            if(vis[i]==false)  
                dfs1(i);
        
        reverse(all(finish));

        vis.assign(n+1,false);
        for(int i=0;i<n;++i){
            int node=finish[i];
            if(vis[node]==false){
                component_number++;
                dfs2(node);
                ll sum=0;
                for(auto j: component){
                    component_group[j]=component_number;
                    sum+=k[j];
                }
                coin[component_number]=sum;
                component.clear();
            }
        }

        component_g.resize(component_number+1);
        for(int i=1;i<=n;++i)
            for(auto j: g[i])
                if( component_group[i]!=component_group[j] )
                    component_g[ component_group[i] ].pb( component_group[j] );

    }

};

ll ans=-1;
ll dp[N];

ll f(int node, kosaraju *scc){
    if(dp[node]!=-1)
        return dp[node];

    ll mx=0;
    for(auto i: scc->component_g[node])
        mx=max(mx,f(i,scc));
    mx+=coin[node];

    return dp[node]=mx;
}

int main(){
    fast;
    // test();

    cin>>n>>m;
    kosaraju scc(n,m);
    for(int i=1;i<=n;i++)
        cin>>k[i];
    for(int i=0;i<m;++i){
        int x,y;
        cin>>x>>y;
        scc.g[x].pb(y);
        scc.transpose_g[y].pb(x);
    }
    scc.make_component_graph();

    n=scc.component_number;
    for(int i=0;i<=n;++i)
        dp[i]=-1;
    for(int i=1;i<=n;i++)
        ans=max(ans,f(i,&scc));
    
    cout<<ans<<"\n";

    return 0;
}