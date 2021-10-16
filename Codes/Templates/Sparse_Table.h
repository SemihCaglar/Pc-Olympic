class SparseTable{
    private:

    int n;
    vi logar;
    vector<vi> table;

    public:

    SparseTable(vi &A){
        this->n=(int) A.size();
        this->logar.resize(n+1);

        for(int i=1,cnt=0;i<=n;i*=2,cnt++)
            for(int j=i;j<i*2 and j<=n;++j)
                logar[j]=cnt;

        table=vector<vi> (n+1,vi(logar[n]+1));

        for(int i=0;i<n;++i)
            table[i][0]=A[i];

        for(int i=1;i<=logar[n];++i)
            for(int j=0;j+(1<<i)<=n;++j)
                table[j][i]=min( table[j][i-1] , table[ j + (1<<(i-1)) ][ i-1 ] );
    }

    int RMQ(int l,int r){
        int logaritma=logar[r-l+1];
        int ans=min( table[l][logaritma] , table[r-(1<<logaritma)+1][logaritma] );
        return ans;
    }

};