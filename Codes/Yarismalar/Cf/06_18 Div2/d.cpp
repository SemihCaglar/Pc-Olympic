#include<semih/competitive.h>

int t,n;
int dp[100005];

int f(int x){
    if(dp[x]!=-1)
        return dp[x];
    int sum=0;
    int cx=x;
    for(int i=2;i*i<=cx;++i){
        while(x%i==0){
            sum+=f(i);
            sum%=2;
            x/=i;
        }
    }
    return dp[x]=sum;
}

int main(){
    fast;
    test();

    memset(dp,-1,sizeof(dp));
    cin>>t;
    while(t--){
        cin>>n;
        if(f(n))
            cout<<"Alice\n";
        else
            cout<<"Bob\n";
    }

    return 0;
}