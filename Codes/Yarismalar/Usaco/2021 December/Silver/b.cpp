#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
#define fi first
#define se second
#define dbg(x) cerr<<#x<<": "<<x<<endl
#define pb push_back
#define test freopen("/home/semih/Desktop/Pc Olympic/test/test.in","r",stdin); freopen("/home/semih/Desktop/Pc Olympic/test/test.out","w",stdout)

const int N=1e5+5;
int t,n,m;
int dad[N];

int union_find(int node){
    return dad[node]==node?node:dad[node]=union_find(dad[node]);
}

void union_set(int x, int y){
    x=union_find(x), y=union_find(y);
    if(x<y) // x>y
        swap(x,y);
    dad[y]=x;
}

bool same(int x, int y){
    return union_find(x)==union_find(y);
}

int dist[N];
bool vis[N];

int main(){
    // test;

    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<=n;++i)
            dad[i]=i;
        for(int i=0;i<m;++i){
            int u,v;
            cin>>u>>v;
            u--,v--;
            union_set(u,v);
        }
        vi bas,son;
        for(int i=0;i<n;++i){
            if(same(0,i))
                bas.pb(i);
            if(same(n-1,i))
                son.pb(i);
        }
        queue<ii> q; // (dugum, mesafe)
        for(auto i: bas)
            q.push({i,0});
        
        for(int i=0;i<=n;++i)
            vis[i]=false;

        while(!q.empty()){
            int node=q.front().fi;
            int mesafe=q.front().se;
            q.pop();

            if(vis[node])
                continue;

            vis[node]=true;
            dist[node]=mesafe;
            if(node>=1)
                q.push({node-1,mesafe+1});
            if(node+1<n)
                q.push({node+1,mesafe+1});
        }
        map<int,int> bastan;
        for(int i=0;i<n;++i){
            int ata=union_find(i);
            int mesafe=dist[i];
            if(bastan.count(ata)==0 or mesafe<bastan[ata])
                bastan[ata]=mesafe;
        }

        for(int i=0;i<=n;++i)
            vis[i]=false;

        for(auto i: son)
            q.push({i,0});

        while(!q.empty()){
            int node=q.front().fi;
            int mesafe=q.front().se;
            q.pop();

            if(vis[node])
                continue;

            vis[node]=true;
            dist[node]=mesafe;
            if(node>=1)
                q.push({node-1,mesafe+1});
            if(node+1<n)
                q.push({node+1,mesafe+1});
        }
        map<int,int> sondan;
        for(int i=0;i<n;++i){
            int ata=union_find(i);
            int mesafe=dist[i];
            if(sondan.count(ata)==0 or mesafe<sondan[ata])
                sondan[ata]=mesafe;
        }

        ll ans=LONG_LONG_MAX;
        for(auto i: bastan){
            ll maybe=1LL*i.se*i.se + 1LL*sondan[i.fi]*sondan[i.fi];
            ans=min(ans,maybe);
        }
        cout<<ans<<"\n";
    }
}