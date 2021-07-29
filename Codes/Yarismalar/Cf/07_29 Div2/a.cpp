#include<semih/competitive.h>

const int N=2e5+5;
int t,n;
int a[N];

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>n;
        forr(i,0,n)
            cin>>a[i];
        ll mx=-1;
        for(int i=1;i<n;++i)
            mx=max(mx,1LL*a[i-1]*a[i]);
        cout<<mx<<"\n";
    }    

    return 0;
}