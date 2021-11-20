#include<semih/competitive.h>

int n,m;
ii a[105];
set<int> x,y;
int ans=INT_MAX;

int main(){
    fast;
    test("balancing");
    // test();

    cin>>n>>m;    
    for(int i=0;i<n;++i){
        cin>>a[i].fi>>a[i].se;
        x.insert(a[i].fi);
        y.insert(a[i].se);
    }
    for(int i: x){
        int apsis=i+1;
        if(apsis>m)
            break;
        for(int j: y){
            int ordinat=j+1;
            if(ordinat>m)
                break;

            int mx=-1;
            int cnt[4]={0,0,0,0};
            for(int k=0;k<n;++k)
                cnt[ (a[k].fi<apsis)*2+(a[k].se<ordinat) ]++;
            for(int k=0;k<4;++k)
                mx=max(mx,cnt[k]);
            ans=min(ans,mx);
        }
    }

    cout<<ans<<"\n";

    return 0;
}
