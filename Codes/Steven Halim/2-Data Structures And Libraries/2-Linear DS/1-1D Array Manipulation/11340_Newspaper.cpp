#include<semih/competitive.h>

void solve(){
    map<char,int> mp;
    int k;
    cin>>k;
    forr(i,0,k){
        int b;
        char a;
        cin>>a>>b;
        mp[a]=b;
    }
    int n;
    cin>>n;
    string s;
    int ans=0;
    getline(cin,s);
    forr(i,0,n){
        getline(cin,s);
        for(auto j:s)
            if(mp.count(j)!=0)
                ans+=mp[j];     
    }
    printf("%.2lf$\n",ans/100.0);
}

int main(){
    test;
    //fast;

    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}