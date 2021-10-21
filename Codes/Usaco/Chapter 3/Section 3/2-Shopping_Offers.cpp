#include<semih/competitive.h>

map<vi,int> dp;
int s,n,b;
map<int,int> code;
ii shopping[6];  // {sayisi,ucreti}

typedef struct offer{
    int a[6];
    int cost;
}offer;

int f(int x){
    for(auto i:code)
        if(i.se==x)
            return i.fi-1;
    code[code.size()+1]=x;
    return code.size()-1;  
}

offer a[105];

int solve(vi v){
    if(dp[v])
        return dp[v];

    int mn=0;
    for(int i=0;i<v.size();++i)
        mn+=v[i]*shopping[i].fi;

    for(int i=0;i<s;++i){
        bool flag=true;
        for(int j=0;j<v.size();++j)
            if(a[i].a[j]>v[j])
                flag=false;
        if(flag==false)
            continue;
        
        vi tmp=v;
        for(int j=0;j<v.size();++j)
            tmp[j]=v[j]-a[i].a[j];
        
        mn=min(mn,solve(tmp)+a[i].cost);
    }
    return dp[v]=mn;
}

int main(){
    fast;
    // test("shopping");

    cin>>s;
    for(int j=0;j<s;++j){
        cin>>n;
        offer tmp;
        for(int i=0;i<6;++i)
            tmp.a[i]=0;
        for(int i=0;i<n;++i){
            int x,y;
            cin>>x>>y;
            tmp.a[f(x)]=y;
        }
        int cost;
        cin>>cost;
        tmp.cost=cost;
        a[j]=tmp;
    }
    cin>>b;
    for(int i=0;i<b;++i){
        int x,y,z;
        cin>>x>>y>>z;
        shopping[f(x)]={z,y};
    }
    vi v;
    for(int i=0;i<b;++i)
        v.pb(shopping[i].se);
    cout<<solve(v)<<"\n";

    return 0;
}