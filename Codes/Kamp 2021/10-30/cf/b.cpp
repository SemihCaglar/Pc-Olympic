#include<semih/competitive.h>

const int N=1e5+5;
int t;
int n,a[N];

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;++i)
            cin>>a[i];
        if(n%2==0){
            cout<<"Yes\n";
            continue;
        }
        bool flag=false;
        for(int i=1;i<n;++i){
            if(a[i]<=a[i-1])
                flag=true;
        }
        if(flag)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }    

    return 0;
}