#include<semih/competitive.h>

const int N=1e5+5;
int t,n,a[N];

int main(){
    fast;
    test();

    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;++i)
            cin>>a[i];
        int ind=0;
        bool flag=true;
        for(int i=0;i<n;++i){
            ind++;
            while(a[i]%(ind+1)==0 and ind>0)
                --ind;
            if(ind==0)
                flag=false;
        }
        if(flag)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }    

    return 0;
}