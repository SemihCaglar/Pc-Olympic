#include<semih/competitive.h>

const int W=40,H=105;
int n,m;
int cell[H][W]; // 1 yukarı, 2 aşağı, 4 sola, 8 sağa
ii exit1=ii(-1,-1),exit2=ii(-1,-1);

bool intable(ii c){
    if(c.fi<=n and c.fi>=0 and c.se<=m and c.se>=0)
        return true;
    return false;
}

void dijkstra(ii coor,map<ii,int> &dist){
    typedef pair<int,ii> iii;
    priority_queue<iii> pq;
    pq.push(iii(0,coor));

    //map<ii,int> dist;
    map<ii,bool> vis;
    dist[coor]=0;

    while(!pq.empty()){
        iii tmp=pq.top();
        pq.pop();
        ii xy=tmp.se;
        int x=xy.fi,y=xy.se;
        
        if(vis[xy])
            continue;

        int adj=cell[x][y];
        
        ii hedef=ii(x-1,y);
        if(adj & 1 and (dist.count(hedef)==0 or dist[xy]+1<dist[hedef]) )
            dist[hedef]=dist[xy]+1,pq.push( iii(dist[xy]*-1-1,ii(x-1,y)) );

        hedef=ii(x+1,y);
        if(adj & 2 and (dist.count(hedef)==0 or dist[xy]+1<dist[hedef]) )
            dist[hedef]=dist[xy]+1,pq.push( iii(dist[xy]*-1-1,ii(x+1,y)) );
        
        hedef=ii(x,y-1);
        if(adj & 4 and (dist.count(hedef)==0 or dist[xy]+1<dist[hedef]) )
            dist[hedef]=dist[xy]+1,pq.push( iii(dist[xy]*-1-1,ii(x,y-1)) );
        
        hedef=ii(x,y+1);
        if(adj & 8 and (dist.count(hedef)==0 or dist[xy]+1<dist[hedef]) )
            dist[hedef]=dist[xy]+1,pq.push( iii(dist[xy]*-1-1,ii(x,y+1)) );
        vis[xy]=true;   
    }
}

void solve(){
    cin>>m>>n;
    string tmp[H*2];
    getline(cin,tmp[0]);
    for(int i=0;i<2*n+1;++i)
        getline(cin,tmp[i]);
    
    for(int i=0;i<2*n+1;i+=2){
        int duvar=i,hucre=i+1;
        for(int j=1;j<2*m+1;j+=2){
            if( (duvar==0 or duvar==2*n) and tmp[duvar][j]==' '){
                ii ans=ii(duvar/2-(duvar==2*n?1:0),j/2);
                if(exit1==ii(-1,-1))
                    exit1=ans;
                else
                    exit2=ans;
            }
            
            if(tmp[duvar][j]==' ' and intable(ii((duvar-2)/2,j/2)) ){
                cell[duvar/2][j/2] |= 1;
                cell[(duvar-2)/2][j/2] |= 2;
            }
        }
        if(hucre==2*n+1)
            continue;
        for(int j=0;j<2*m+1;j+=2){
            if( (j==0 or j==2*m) and tmp[hucre][j]==' '){
                ii ans=ii(hucre/2,j/2-(j==2*m?1:0));
                if(exit1==ii(-1,-1))
                    exit1=ans;
                else
                    exit2=ans;
            }
            
            if(tmp[hucre][j]==' ' and intable(ii(hucre/2,(j-2)/2)) ){
                cell[hucre/2][j/2] |= 4;
                cell[hucre/2][(j-2)/2] |= 8;
            }
        }

    }
    map<ii,int> dist1,dist2;
    dijkstra(exit1,dist1);
    dijkstra(exit2,dist2);

    int mx=-1;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j){
            ii coordinate=ii(i,j);
            mx=max(mx, min(dist1[coordinate],dist2[coordinate]) );
        }
    cout<<mx+1<<endl;
}