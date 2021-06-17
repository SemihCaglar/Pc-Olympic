#include<semih/competitive.h>

ll dp[10005][30];
vi coins; 

ll f(int n,int m){
    if(n<0)
        return 0;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(m==0){
        if(n==0)
            return dp[n][m] = 1;
        return dp[n][m] = 0;
    }
    return dp[n][m]=f(n,m-1)+f(n-coins[m-1],m);
}

void solve(){
    int n,m; 
    cin>>m>>n;
    for(int i=0;i<m;++i){
        int a;
        cin>>a;
        coins.pb(a);
    }   
    memset(dp,-1,sizeof(dp));
    cout<<f(n,m)<<'\n';
}