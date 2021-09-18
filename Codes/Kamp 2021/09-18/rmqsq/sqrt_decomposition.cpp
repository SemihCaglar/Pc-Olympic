#include<semih/competitive.h>

const int N=2e5+5;
int n,q,a[N];
int sqr[1005];
int kok;

int main(){
    fast;
    // test();

    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    kok=sqrt(n);
    for(int i=0;i<n/kok;++i){
        int mn=INT_MAX;
        for(int j=0;j<kok;++j)
            mn=min(mn,a[i*kok+j]);
        sqr[i]=mn;
    }    

    cin>>q;
    for(int i=0;i<q;++i){
        int l,r;
        cin>>l>>r;
        int left= (l+kok-1)/kok*kok;
        int right= (r+1)/kok*kok;
        int ans=INT_MAX;
        for(int j=l;j<=min(r,left);++j)
            ans=min(ans,a[j]);
        for(int j=max(l,right);j<=r;++j)
            ans=min(ans,a[j]);
        for(int j=left/kok;j<right/kok;++j)
            ans=min(ans,sqr[j]);
        cout<<ans<<"\n";
    }    

    return 0;
}