#include<semih/competitive.h>

int h,w,n;
map<ii,int> a;
map<ii,int> dp;
map<ii,bool> gray;

bool intable(ii coord,ii now){
    if(coord.fi>=1 and coord.fi<=h and coord.se>=1 and coord.se<=w and a.count(coord) and a[coord]>a[now])
        return true;
    return false;
}

int f(ii coord){
    if(dp.count(coord))
        return dp[coord];
    
    if(gray[coord])
        return 0;
    gray[coord]=true;
    int mx=0;

    bool flag=false;

    if(intable({coord.fi,coord.se+1},coord))
        mx=max(mx,f({coord.fi,coord.se+1})),flag=true;

    if(intable({coord.fi,coord.se-1},coord))
        mx=max(mx,f({coord.fi,coord.se-1})),flag=true;

    if(intable({coord.fi+1,coord.se},coord))
        mx=max(mx,f({coord.fi+1,coord.se})),flag=true;

    if(intable({coord.fi-1,coord.se},coord))
        mx=max(mx,f({coord.fi-1,coord.se})),flag=true;
    
    gray[coord]=false; 
    return dp[coord]=mx+flag;
}

int main(){
    fast;
    // test();

    cin>>h>>w>>n;
    for(int i=0;i<n;++i){
        int x,y,z;
        cin>>x>>y>>z;
        a[{x,y}]=z;
    }  
    for(auto i:a)
        cout<<f(i.fi)<<"\n";

    return 0;
}