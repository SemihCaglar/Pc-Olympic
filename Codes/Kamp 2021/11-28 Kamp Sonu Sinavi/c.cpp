#include<semih/competitive.h>

const int N=3e3+5;
ll dp[N][4]; 
ll n;
ll a[N];
ll b[N];

ll f(ll x, ll y){   // x. indexin dahil olduğu ve y sayi almamiz gereken durum.
    if(y==1)
        return b[x];

    ll &ref=dp[x][y];
    if(ref!=-1)
        return ref;

    ll mn=LONG_LONG_MAX;
    for(ll i=x-1;i>=y-1;--i){
        if(a[i]<a[x] and f(i,y-1)!=LONG_LONG_MAX)
            mn=min(mn,0LL+f(i,y-1)+b[x]);
    }
    return ref=mn;
}

int main(){
    fast;
    // test();

    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i)
        cin>>b[i];
    
    for(int i=0;i<=n;++i)
        dp[i][0]=dp[i][1]=dp[i][2]=dp[i][3]=-1;

    ll mn=LONG_LONG_MAX;
    for(int i=1;i<=n;++i)
        mn=min(mn,f(i,3));

    if(mn==LONG_LONG_MAX)
        cout<<-1<<"\n";
    else
        cout<<mn<<"\n";    

    return 0;
}