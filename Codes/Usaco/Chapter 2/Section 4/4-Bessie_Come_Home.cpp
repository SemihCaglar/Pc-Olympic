#include<semih/competitive.h>

typedef pair<char,int> ci;
typedef vector<ci> vci;
typedef map<char,vci> mcc;

int m;
mcc edges;
map<char,int> dist;
map<char,bool> vis;

void solve(){
    cin>>m;
    forr(i,0,m){
        char a,b;
        int yol;
        cin>>a>>b>>yol;
        edges[a].pb(ci(b,yol));
        edges[b].pb(ci(a,yol));
    }
    typedef pair<int,char> ic;
    priority_queue<ic> pq;
    pq.push(ic(0,'Z'));
    dist['Z']=0;

    while(!pq.empty()){
        ic tmp=pq.top();
        pq.pop();
        int uzaklik=tmp.fi*-1;
        char v=tmp.se;
        if(v<'Z' and v>='A'){
            cout<<v<<sp<<uzaklik<<endl;
            return;
        }
        if(vis[v])
            continue;
        for(ci i:edges[v]){
            char hedef=i.fi;
            int mesafe=i.se;
            if(dist.count(mesafe)==0 or uzaklik+mesafe<dist[hedef]){
                dist[hedef]=uzaklik+mesafe;
                pq.push(ic(-uzaklik-mesafe,hedef));
            }
        }
        vis[v]=true;
    }

}