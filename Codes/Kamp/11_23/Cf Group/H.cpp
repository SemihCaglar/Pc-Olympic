#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef vector<int> vi;

int n,m;
vi v[N];
int component[N];
vector<priority_queue<int>> gruplar;
int sayi;

void dfs(int x){
    component[x]=sayi;
    if(gruplar.size()<=sayi){
        priority_queue<int> q;
        gruplar.push_back(q);
    }
    gruplar[sayi].push(-x);

    for(int i=0;i<v[x].size();++i){
        if(component[v[x][i]]==-1)
            dfs(v[x][i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(component,-1,sizeof(component));
    for(int i=1;i<=n;++i){
        if(component[i]==-1){
            dfs(i);
            sayi++;
        }
    }
    cout<<gruplar.size()<<'\n';
    for(auto &i:gruplar){
        cout<<i.size()<<' ';
        while(!i.empty()){
            int t=i.top()*-1;
            i.pop();
            cout<<t<<' ';
        }
        cout<<'\n';
    }

}