#include<semih/competitive.h>

const int MOD=1e9+7;
int l,r;
int ar[3];

int mod(int a,int b){
    int res=a%b;
    if(res<0)
        res+=b;
    return res;
}

int dp[200005][3];

int f(int n,int rem){
    if(n==0 and rem!=0)
        return -1;
    if(n==0)
        return 1;
    if(dp[n][rem]!=-1)
        return dp[n][rem];
    ll res=0;
    ll tmp;
    tmp=f(n-1,0);
    if(tmp!=-1)
        res+=1LL*f(n-1,0)*ar[mod(rem-0,3)]%MOD;
    res%=MOD;
    
    tmp=f(n-1,1);
    if(tmp!=-1)
        res+=1LL*f(n-1,1)*ar[mod(rem-1,3)]%MOD;
    res%=MOD;
    
    tmp=f(n-1,2);
    if(tmp!=-1)
        res+=1LL*f(n-1,2)*ar[mod(rem-2,3)]%MOD;
    res%=MOD;
    
    return dp[n][rem]=res;
}

void solve(){
    int n;
    cin>>n>>l>>r;
    int bas,son;
    bas=(l+2)/3,son=(r)/3;
    ar[0]=son-bas+1;
    bas=(l+1)/3,son=r-1>=0?(r-1)/3:-1;
    ar[1]=son-bas+1;
    bas=(l+0)/3,son=r-2>=0?(r-2)/3:-1;
    ar[2]=son-bas+1;
    for(int i=0;i<=n;++i)
        for(int j=0;j<3;++j)
            dp[i][j]=-1;
    dbg(ar[0]),dbg(ar[1]),dbg(ar[2]);
    cout<<f(n,0);
}