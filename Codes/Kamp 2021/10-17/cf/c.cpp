#include<semih/competitive.h>

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

const int N=1e6+5;
int n,m,q;
string lab;
vi a;

int main(){
    fast;
    // test();

    cin>>n>>m;
    lab.resize(m);
    a.resize(m);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j){
            char x;
            cin>>x;
            if(j>0 and lab[j]=='X' and lab[j-1]=='X')
                a[j]=-1;
            lab[j]=x;
        }
    SparseTable ST(a);
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        if(l==r){
            cout<<"YES\n";
            continue;
        }
        l--,r--;
        if(ST.RMQ(l+1,r)==-1)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }     

    return 0;
}