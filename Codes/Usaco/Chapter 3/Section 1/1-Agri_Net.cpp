#include<semih/competitive.h>
const int N=105;

vii v[N];

int n;
bool vis[N];
int dist[N];

void solve(){
    cin>>n;
    forr(i,0,n)
        forr(j,0,n){
            int a;
            cin>>a;
            if(i==j)
                continue;
            v[i].pb(ii(j,a));
        }
    priority_queue<ii> pq;
    pq.push(ii(0,0));
    dist[0]=0;
    memset(dist,-1,sizeof(dist));

    int result=0;
    
    while(!pq.empty()){
        ii tmp=pq.top();
        pq.pop();
        int ver=tmp.se,distance=tmp.fi*-1;
        if(vis[ver])
            continue;
        result+=distance;
        vis[ver]=true;
        for(auto i:v[ver]){
            int hedef=i.fi,uzaklik=i.se;
            if(dist[hedef]==-1 or uzaklik<dist[hedef]){
                dist[hedef]=uzaklik;
                pq.push(ii(-uzaklik,hedef));
            }
        }
    }
    cout<<result<<endl;
}
