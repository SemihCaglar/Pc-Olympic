class LowestCommonAncestor{

    public:
    
    vi depth;                            // derinlik
    vector<vi> parent;                   // parent[i][j]: i. node'un 2^j. atası
    vi order;                            // dfs sıraları

    void dfs(int node,int dad,vi *tree){
        parent[node][0]=dad;
        depth[node] = node==1 ? 1 : depth[dad]+1;
        if(node!=1)
            order.pb(node);
        for(int i:tree[node])
            if(i!=dad)
                dfs(i,node,tree); 
    }

    LowestCommonAncestor(int n,vi *tree){
        this->parent=vector<vi> (n+5,vi(32));
        this->depth.resize(n+5);

        for(int &i: parent[1])
            i=-1;

        dfs(1,-1,tree);

        for(auto i: order)
            for(int j=1;j<=30;++j)
                parent[i][j] = parent[i][j-1]==-1 ? -1 : parent[ parent[i][j-1] ][j-1] ;
    }

    int LCA(int a,int b){
        if(depth[a]<depth[b])
            swap(a,b);
        
        for(int i=30;i>=0;--i)
            if( parent[a][i]!=-1 and depth[ parent[a][i] ] >= depth[b] )
                a=parent[a][i];
        
        if(a==b)
            return a;
        
        for(int i=30;i>=0;--i)
            if(parent[a][i]!=parent[b][i])
                a=parent[a][i],b=parent[b][i];

        return parent[a][0];
    }

};