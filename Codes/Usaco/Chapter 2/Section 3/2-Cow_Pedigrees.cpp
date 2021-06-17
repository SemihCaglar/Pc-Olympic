#include<semih/competitive.h>

const int MOD=9901;
int n,h;
int dp[205][105];

int f(int x,int y){
    if(dp[x][y]!=-1)
        return dp[x][y];
    
    if((x+1)/2<y)
        return dp[x][y]=0;
    if(x==1 and y==1)
        return dp[x][y]=1;
    if(x==0 and y==0)
        return dp[x][y]=1;
    if(y==0)
        return dp[x][y]=0;

    int tot=0;
    for(int i=1;i<x-1;i++){
        int res=f(i,y-1);
        if(res==0) 
            continue;
        int sum=0;
        for(int j=0;j<y;++j){
            sum+=f(x-i-1,j)*(y-1==j?1:2)%MOD;
            sum%=MOD;
        }
        tot+=res*sum%MOD;
        tot%=MOD;
    }
    return dp[x][y]=tot;
}

void solve(){
    cin>>n>>h;
    memset(dp,-1,sizeof(dp));
    cout<<f(n,h)<<endl;
}