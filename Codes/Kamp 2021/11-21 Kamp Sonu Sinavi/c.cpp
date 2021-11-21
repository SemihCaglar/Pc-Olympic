#include<semih/competitive.h>

const int N=2e5+5;
int t,n;
ll c[N],a[N],b[N];
ll dp[N][2];

ll f(int ind, bool start){
    if(ind==n-1)
        return c[ind]-1;
    ll &ref=dp[ind][start];
    if(ref)
        return ref;
    ll alt=max(a[ind+1],b[ind+1]);
    ll ust=min(a[ind+1],b[ind+1]);
    ll h=ust-1+c[ind]-alt;

    if(h==0 and start==true)
        h=c[ind]-1;
    if(ust==alt && start!=true)
        return c[ind]-1;
    else if(ust==alt)
        return ref = 2+f(ind+1,false);
    if(start==true)
        return ref = (alt-ust)+2+f(ind+1,false) ;
    else
        return ref = max( c[ind]-1, h+2+f(ind+1,false) );
}

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        ll mx=-1;
        cin>>n;
        for(int i=0;i<n;++i)
            cin>>c[i];
        for(int i=0;i<n;++i)
            cin>>a[i];
        for(int i=0;i<n;++i)
            cin>>b[i];

        for(int i=0;i+1<n;++i)
            mx=max(mx,f(i,true));
        cout<<mx<<"\n";
        for(int i=0;i<=n;++i)
            dp[i][0]=dp[i][1]=0;
    }    

    return 0;
}