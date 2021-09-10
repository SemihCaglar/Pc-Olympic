#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

int n,m;
bool vis[N];
vector<iii> edges;

int main(){
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int a,b,w;
        cin>>a>>b>>w;
        edges.push_back(iii(w,ii(a,b)));
    }
    sort(edges.begin(),edges.end());
    int ind=0;
    int cnt=0;
    while(cnt!=n){
        iii tmp=edges[ind];
        ii uv=tmp.second;
        if(vis[uv.first]==1&&vis[uv])
    }
}