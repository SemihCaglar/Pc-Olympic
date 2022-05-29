#include "game.h"

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

#define pb push_back
#define fi first 
#define se second

vector<vi> g; // graf

bool flag;
vector<bool> vis;
int cur;
int kk;

void dfs(int node, bool neblm){
    if(node==cur and neblm==0){
        flag=true;
        return;
    }
    if(vis[node])
        return;
    vis[node]=true;
    for(auto i: g[node]){
        dfs(i,0);
    }
}

void init(int n, int k) {
    kk=k;
    g.resize(n+5);
    vis.resize(n+5);
    for(int i=0;i+1<k;++i)
        g[i].pb(i+1);
}

int add_teleporter(int u, int v) {
    if(flag)
        return 1;
    g[u].pb(v);
    for(int i=kk-1;i>=0;--i){
        cur=i;
        flag=false;
        dfs(i,1);
        if(flag)
            return 1;
    }
    for(int i=0;i<vis.size();++i)
        vis[i]=0;
    return 0;
}
