#include<semih/competitive.h>
typedef unsigned long long int ulli;

int t,n,k;
int a[11];
ulli sum;
ulli onluk[11];

int main(){
    fast;
    // test();
    {
        ulli carpim=1;
        for(int i=0;i<11;++i)
            onluk[i]=carpim,carpim*=10;
    }
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0;i<n;++i)
            cin>>a[i];
        sum=0;
        
        ll birsayisi=onluk[a[1]]-2; // kaç tane 1 olmali?
        if(k<birsayisi)
            birsayisi=k;
        sum+=birsayisi;
        k-=birsayisi;

        for(int i=1;i+1<n;++i){
            if(k==0)
                break;
            ll oluru=onluk[a[i+1]-a[i]]-1;
            if(k<oluru)
                oluru=k;
            k-=oluru;
            sum+=onluk[a[i]]*oluru;
        }
        if(k!=0){
            sum+=onluk[a[n-1]]*k;
        }
        cout<<sum+1<<"\n";
    }

    return 0;
}