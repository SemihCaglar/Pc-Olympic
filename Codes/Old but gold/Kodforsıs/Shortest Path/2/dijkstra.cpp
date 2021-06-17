#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int n,m;
typedef pair<int,int> ii;
vector<ii> v[N];
int path[N];
int minimum[N];
bool vis[N];

void f(int n){
    int a=path[n];
    if(n!=1)
        f(a);
    cout<<n<<' ';
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        v[a].push_back(ii(b,w));
        v[b].push_back(ii(a,w));
    }
    for(int i=1;i<=n;++i)
        minimum[i]=-1;
    minimum[1]=0;
    priority_queue<ii> pq; // (-distance,dugum)
    pq.push(ii(0,1));
    path[1]=1;
    while(!pq.empty()){
        int tmp=pq.top().second;
        pq.pop();
        if(vis[tmp])
            continue;
        for(int i=0;i<v[tmp].size();++i){
            int b=v[tmp][i].first;
            if(vis[b])
                continue;
            int w=v[tmp][i].second;
            if(minimum[b] == -1){
                minimum[b]=minimum[tmp]+w;
                path[b]=tmp;
                pq.push(ii(minimum[b]*-1,b));
            }
            else if (minimum[tmp]+w<minimum[b]){
                path[b]=tmp;
                minimum[b]=minimum[tmp]+w;
                pq.push(ii(minimum[b]*-1,b));
            }
        }
        vis[tmp]=true;
    }
    if(minimum[n]==-1)
        cout<<-1;
    else 
        f(n);
    return 0;
}