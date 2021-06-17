#include<semih/competitive.h>

int m,n;
vii worth;

int dp[10005];

int f(int x){
    if(x==0)
        return 0;
    if(dp[x]!=-1)
        return dp[x];
    
    int mx=0;
    for(auto i:worth)
        if(x>=i.se){
            int belki=f(x-i.se)+i.fi;
            mx=max(mx,belki);
        }
    return mx;
}

void solve(){
    cin>>m>>n;
    forr(i,0,n){
        int a,b;
        cin>>a>>b;
        worth.pb(ii(a,b));
    }
    memset(dp,-1,sizeof(dp));
    cout<<f(m)<<endl;

}