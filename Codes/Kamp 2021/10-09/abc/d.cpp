#include<semih/competitive.h>

const int N=3e3+5;
const int MOD=998244353;

int n;
int a[N],b[N];
int dp[N][N];
ll sum;

int f(int x,int y){ // x. indekse y gelirse
    if(x+1==n)
        return 1;

    if(dp[x][y]!=-1)
        return dp[x][y];    

    ll ans=0;
    for(int i=max(y,a[x+1]);i<=b[x+1];++i){
        ans+=f(x+1,i);
        ans%=MOD;
    }
    return dp[x][y]=ans;
}

int main(){
    fast;
    // test();
    for(int i=0;i<=3e3;++i)
        for(int j=0;j<=3e3;++j)
            dp[i][j]=-1;

    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];    
    for(int i=0;i<n;++i)
        cin>>b[i];    

    for(int i=a[0];i<=b[0];++i)
        sum+=f(0,i),sum%=MOD;     

    cout<<sum<<"\n";

    return 0;
}