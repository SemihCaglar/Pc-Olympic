#include<semih/competitive.h>

const int N=1e5+5;
int n;
map<int,int> mp;

int main(){
    fast;
    // test();

    cin>>n;
    for(int i=1;i<n;++i){
        int a,b;
        cin>>a>>b;
        mp[a]++,mp[b]++;
    }

    bool flag=false;
    for(auto i:mp)
        if(i.se==n-1)
            flag=true;
    
    if(flag)
        cout<<"Yes\n";
    else
        cout<<"No\n";

    return 0;
}