#include<semih/competitive.h>
const int N=2e6+5;

int dp[N];
int k,n;
int pul[60];

void solve(){
    cin>>k>>n;
    forr(i,0,n)
        cin>>pul[i];
    memset(dp,-1,sizeof(dp));

    int i;
    dp[0]=0;
    for(i=0;true;++i){
        if(dp[i]==-1 or dp[i]>k)
            break;
        for(int j=0;j<n;++j){
            int hedef=i+pul[j],sayi=dp[i]+1;
            if( hedef<=N-5 and(dp[hedef]==-1 or sayi<dp[hedef]) )
                dp[hedef]=sayi;
        }
    }
    cout<<i-1<<endl;
}