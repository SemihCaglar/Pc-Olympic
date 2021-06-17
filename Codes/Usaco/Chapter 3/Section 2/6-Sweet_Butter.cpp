#include<semih/competitive.h>

int n,m,c;
vii v[1500];
int loc[1500];
int asp[1500][1500];

void aspHesapla(){
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            asp[i][j]=-1;
    for(int i=1;i<=n;++i){
        
        bool vis[1500]={};
        typedef pair<double,int> di;
        priority_queue<di> pq; // (-dist,vertex)
        asp[i][i]=0;
        pq.push(di(0,i));
        while(!pq.empty()){
            di tmp=pq.top();
            pq.pop();
            double dist=tmp.fi*-1;
            int ver=tmp.se;
            if(vis[ver])
                continue;

            for(int j=0;j<v[ver].size();++j){
                int hedef=v[ver][j].fi;
                double belki=dist+v[ver][j].se;
                if(asp[i][hedef]==-1 or belki<asp[i][hedef]){
                    asp[i][hedef]=belki;
                    pq.push(di(belki*-1,hedef));
                }
            }
            vis[ver]=true;
        }

    }
}

int main(){
    fast;
    // test("butter");
    cin>>c>>n>>m;
    forr(i,1,c+1)
        cin>>loc[i];
    forr(i,0,m){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].pb({b,c});
        v[b].pb({a,c});
    }

    aspHesapla();
    int mn=INT_MAX;
    for(int i=1;i<=n;++i){
        int sum=0;
        bool flag=true;
        for(int j=1;j<=c;++j){
            int a=loc[j],b=i;
            if(asp[a][b]==-1){
                flag=false;
                break;
            }
            sum+=asp[a][b];
        }
        if(flag)
            mn=min(mn,sum);
    }
    cout<<mn<<"\n";
    
    return 0;
}