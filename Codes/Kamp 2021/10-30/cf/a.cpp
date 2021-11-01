#include<semih/competitive.h>

const int N=105;
int t;
ll n;
ll a[N];

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;++i)
            cin>>a[i];
        int cur=0;
        ll sum=-1;

        for(int i=0;i<n;++i){
            if(a[i]>cur)
                sum+=a[i]-cur,cur=a[i]+1;
            else
                cur++;
        }
        cout<<sum<<"\n";
    }

    return 0;
}