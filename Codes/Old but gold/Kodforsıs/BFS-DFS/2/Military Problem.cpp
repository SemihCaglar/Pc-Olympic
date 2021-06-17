// https://codeforces.com/problemset/problem/1006/E
#include<stdio.h>
#include<vector>
const int N=2e5+20;
using namespace std;
vector<int> edge[N];
vector<int> dfs;
int len[N];
int start[N];
int u,k;

void f(int node){
    start[node]=dfs.size()+1;
    dfs.push_back(node);
    for(int i=0;i<edge[node].size();++i)
        f(edge[node][i]);
}

int main(){
    
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;++i){
        int a;
        scanf("%d",&a);
        edge[a].push_back(i);
    }
    for(int i=n;i>0;--i){
        len[i]=1;
        for(int j=0;j<edge[i].size();++j)
            len[i]+=len[ edge[i][j] ];   
    }
    f(1);
    while(q--){
        scanf("%d%d",&u,&k);
        if(len[u]<k)
            printf("-1\n");
        else
            printf("%d\n",dfs[start[u]+k-2]);
    }
//    getchar();
//    getchar();
}