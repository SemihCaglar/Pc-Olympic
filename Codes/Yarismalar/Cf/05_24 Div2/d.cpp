#include<semih/competitive.h>
const int N=1000005;
const int MOD=998244353;

int n;

int dp[N];

int f(int x){
    if(x==1)
        return 1;
    ll res=1,y=x;
    for(int i=2;i*i<=y;++i){
      if(x%i==0){
          int cnt=0;
          for(;x%i==0;x/=i,cnt++);
          res*=cnt+1;
          res%=MOD;
      }  
    }
    if(res==1)
        res=2;
    return res;
}

int main(){
    fast;
    // test();

    cin>>n;
    dp[0]=0;
    dp[1]=1;
    ll sum=0;
    for(int i=1;i<=n;++i){
        dp[i]=(0LL+sum+f(i))%MOD;
        sum+=dp[i];
        sum%=MOD;
    }
    cout<<dp[n];

    return 0;
}