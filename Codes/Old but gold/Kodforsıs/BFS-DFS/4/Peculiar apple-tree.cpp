// https://codeforces.com/problemset/problem/930/A
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> ii;
const int N=1e5+100;
vector<int> v[N];
int dep[N];
int n;

int dfs(){
    int ans=0;
    queue<pair<int,int>> q;
    q.push(make_pair(1,1));
    while(!q.empty()){
        ii temp=q.front();
        q.pop();
        ++dep[temp.second];
        for(int i=0;i<v[temp.first].size();++i){
            q.push(make_pair( v[temp.first][i] , temp.second+1 ));
        }
    }
    for(int i=1;i<=n;++i){
        ans+=dep[i]%2;
    }
    return ans;
}

int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;++i){
        int a;
        scanf("%d",&a);
        v[a].push_back(i);
    }
    printf("%d",dfs());
    getchar();
    getchar();
}