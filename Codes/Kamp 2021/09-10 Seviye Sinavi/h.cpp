#include<semih/competitive.h>

const int N=1005;
const int MOD=1e9+7;

int n,m;
int dp1[15][N],dp2[15][N];
ll ans;

int f1(int ind,int x){
    ll sum=0;
    if(dp1[ind][x]!=-1)
        return dp1[ind][x];
    if(ind==1)
        return 1;

    for(int i=1;i<=x;++i){
        sum+=f1(ind-1,i);
        sum%=MOD;
    }
    return dp1[ind][x]=sum;
}

int f2(int ind,int x){
    int sum=0;
    if(dp2[ind][x]!=-1)
        return dp2[ind][x];
    if(ind==1)
        return 1;

    for(int i=x;i<=n;++i){
        sum+=f2(ind-1,i);
        sum%=MOD;
    }
    return dp2[ind][x]=sum;
}

int main(){
    fast;
    // test();
    cin>>n>>m;

    for(int i=0;i<=m+3;++i)
        for(int j=0;j<=n+3;++j)
            dp1[i][j]=dp2[i][j]=-1;
    
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;++j){
            ans+=1LL*f1(m,i)*f2(m,j);
            ans%=MOD;
        }
    cout<<ans<<"\n";

    return 0;
}