#include<semih/competitive.h>

class SparseTable{
    private:

    int n;
    vi logar;
    vector<vi> table;

    public:
    SparseTable(){

    }

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

const int N=260;
int n;
char a[N][N];

vi yatay,dikey;
bool dp[N][N]; // (row,column)
SparseTable minyatay[N],mindikey[N];

int main(){
    fast;
    // test("range");

    cin>>n;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cin>>a[i][j];

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)
            yatay.pb(a[i][j]-'0');
        minyatay[i]=SparseTable(yatay); 
        yatay.clear();
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)
            dikey.pb(a[j][i]-'0');
        mindikey[i]=SparseTable(dikey); 
        dikey.clear();
    }
    
    for(int i=0;i<=n;++i)
        for(int j=0;j<=n;++j)
            dp[i][j] = a[i][j]=='1';

    for(int size=2;size<=n;++size){
        int cnt=0;
        for(int x=0;x+size<=n;++x)
            for(int y=0;y+size<=n;++y){
                if(dp[x][y]==true and mindikey[y+size-1].RMQ(x,x+size-1) and minyatay[x+size-1].RMQ(y,y+size-1))
                    dp[x][y]=true,cnt++;
                else
                    dp[x][y]=false;
            }
        if(cnt==0)
            break;
        cout<<size<<" "<<cnt<<"\n";
    }

    return 0;
}