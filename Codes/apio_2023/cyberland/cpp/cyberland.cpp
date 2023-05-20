#include "cyberland.h"

#include <vector>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define pb push_back

const int MAXN=1e5+5;
vii ar[MAXN];
bool vis[MAXN];
ll dist[MAXN];
bool valid[MAXN];

void dfs(int node, int dad, int H){
    valid[node]=true;
    for(auto next: ar[node]){
        if(next.fi==dad or next.fi==H)
            continue;
        dfs(next.fi,node,H);
    }
}

double solve(int N, int M, int K, int H, std::vector<int> x, std::vector<int> y, std::vector<int> c, std::vector<int> arr) {
    for(int i=0;i<M;++i){
        int u=x[i],v=y[i];
        ar[u].pb({v,c[i]});
        ar[v].pb({u,c[i]});
    }   

    for(int i=0;i<=N;++i)
        dist[i]=LLONG_MAX;
    priority_queue<pair<ll,int>> q; // (-dist,node)
    q.push({0,H});
    while(!q.empty()){
        ll d=q.top().fi*-1;
        int node=q.top().se;
        q.pop();
        if(vis[node])
            continue;
        dist[node]=d;
        vis[node]=true;
        for(auto next: ar[node]){
            if(d+next.se>dist[next.fi])
                continue;
            dist[next.fi]=d+next.se;
            q.push({(d+next.se)*-1,next.fi});
        }
    }
    dfs(0,-1,H);

    ll mn=dist[0];

    for(int i=0;i<N;++i)
        if(arr[i]==0 and valid[i])
            mn=min(mn,dist[i]);            
    
    for(int i=0;i<=N;++i){
        ar[i].clear();
        vis[i]=false;
        dist[i]=-1;
        valid[i]=false;
    }

    if(mn==LLONG_MAX)
        return -1;
    return mn;
}