#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
vector<int> v[N];
 
int geceninsan[N];
int insansayisi[N];
int happiness[N];
 
int mutlu(int i,bool&onemli){
    onemli=false;
    if((geceninsan[i]+happiness[i])%2){
        onemli=true;
        return 5;
    }
    int result=(geceninsan[i]+happiness[i])/2;
    if(result<0||result>geceninsan[i]){
        onemli=true;
        return 5;
    }
    return result;
}
 
int f(int a,int b,int x){
    if((a-b)>=insansayisi[x])
        return b;
    return b-(insansayisi[x]-(a-b));
}
 
bool dfs(int x,int dad){
    if(v[x].size()==1&&x!=1){
        return true;
    }
{    int sum=0;
    for(int i=0;i<v[x].size();++i){
        if(v[x][i]==dad)
            continue;
        bool hey; int arti=mutlu(v[x][i],hey); if(hey) return false;
        sum+=arti;
    }
    bool hey;
    int neblm=mutlu(x,hey); if(hey) return false;
    int oluru=f(geceninsan[x],neblm,x);
    if(sum>oluru)
        return false;
}    
    for(int i=0;i<v[x].size();++i){
        if(v[x][i]==dad)
            continue;
        if(dfs(v[x][i],x)==false)
            return false;
    }    
    return true;
}
 
int dfs2(int x,int dad){
    geceninsan[x]=0;
    if(v[x].size()==1&&x!=1)
        return geceninsan[x]=insansayisi[x];
    
    for(int i=0;i<v[x].size();++i){
        if(v[x][i]==dad)
            continue;
        geceninsan[x]+=dfs2(v[x][i],x);
    }
    return geceninsan[x]+=insansayisi[x];
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        
        for(int i=1;i<=n;++i)
            cin>>insansayisi[i];
        
        for(int i=1;i<=n;++i)
            cin>>happiness[i];
 
        for(int i=1;i<n;++i){
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs2(1,0);
        bool neblm=dfs(1,0);
        if(neblm==true){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        for(int i=0;i<n+5;++i){
            v[i].clear();
        }
 
    }
}
