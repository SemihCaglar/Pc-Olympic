#include<semih/competitive.h>

const int N=2e5+5;
int n,q,a[N];
int logar[N];
int sp_table[20][N];

int main(){
    fast;
    // test();

    cin>>n;
    for(int i=1,cnt=0;i<=n;i*=2,cnt++)
        for(int j=i;j<i*2;++j)
            logar[j]=cnt;
    for(int i=0;i<n;++i){
        cin>>a[i];
        sp_table[0][i]=a[i];
    }
    for(int i=1;i<=logar[n];++i)
        for(int j=0;j+(1<<i)<=n;++j)
            sp_table[i][j]=min( sp_table[i-1][j] , sp_table[i-1][ j+ (1<<(i-1)) ] );

    cin>>q; 
    while(q--){
        int l,r;
        cin>>l>>r;
        int logaritma=logar[r-l+1];
        int ans=min( sp_table[logaritma][l] , sp_table[logaritma][r-(1<<logaritma)+1] );
        cout<<ans<<"\n";
    }
    

    return 0;
}