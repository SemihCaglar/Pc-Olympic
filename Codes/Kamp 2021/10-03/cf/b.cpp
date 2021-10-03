#include<semih/competitive.h>

int n,k;
ll a[55];

ll dp[55][55];

ll f(int x,int y){ // x. sıradayız. y bölüm olacak.
    if(dp[x][y]!=-1)
        return dp[x][y];

    if(y==1){
        ll toplam=0;
        for(int i=x;i<n-y+2;++i)
            toplam = toplam + a[i];
        return dp[x][y]=toplam;
    }

    ll toplam=0;
    ll mx=-1;

    for(int i=x;i<n-y+2;++i){
        toplam = toplam + a[i];
        ll belki= f(i+1,y-1);
        mx=max(mx, toplam & belki);
    } 

    return dp[x][y]=mx;
}

int main(){
    fast;
    // test();

    cin>>n>>k;    
    for(int i=1;i<=n;++i)
        cin>>a[i];
    
    for(int i=0;i<55;++i)
        for(int j=0;j<55;++j)
            dp[i][j]=-1;

    cout<<f(1,k)<<"\n";

    return 0;
}