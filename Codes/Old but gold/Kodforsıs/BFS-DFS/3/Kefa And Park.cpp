// https://codeforces.com/problemset/problem/580/C
#include<stdio.h>
#include<vector>
using namespace std;
const int N=2e5+20;
bool cats[N];
vector<int> v[N];
int n, m, answer=0;

void dfs(int edge,int cat,int dad){
    int newcat=cats[edge]?cat+1:0;
    if(newcat>m)
        return;
    if(v[edge].size()==1&&edge-1){
        answer++;
        return;
    }
    for(int i=0;i<v[edge].size();++i)
        if(v[edge][i]!=dad)
            dfs(v[edge][i],newcat,edge);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",cats+i);
    }
    for(int i=0;i<n-1;++i){
        int a, b;
        scanf("%d%d", &a, &b);
        v[b].push_back(a);
        v[a].push_back(b);
    }
    dfs(1,0,-1);
    printf("%d",answer);
    getchar();
    getchar();
}