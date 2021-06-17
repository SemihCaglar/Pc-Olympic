#include<semih/competitive.h>
typedef pair<ii,int> iii;

vii cows;
ii farmer;

vii v[15][15];
int shorpath[15][15][15][15];

bool inboard(ii c){
    int x=c.fi,y=c.se;
    if(x<=10 and x>=1 and y<=10 and y>=1)
        return true;
    return false;
}

void bfs(ii src){
    typedef pair<iii,int> cow; // yukarı 1, sağ 2, aşağı 3, sola 4
    int vis[15][15][5];
    forr(i,0,15)
        forr(j,0,15)
            forr(k,0,5)
                vis[i][j][k]=-1;

    queue<cow> q;
    q.push(_mp( _mp(src,0), 1) );

    while(!q.empty()){
        cow tmp=q.front();
        q.pop();
        int x=tmp.fi.fi.fi,y=tmp.fi.fi.se;
        if(vis[x][y][tmp.se]!=-1 and vis[x][y][tmp.se]<=tmp.fi.se)
            continue;
        if(shorpath[src.fi][src.se][x][y]==0)
            shorpath[src.fi][src.se][x][y]=tmp.fi.se;
        else
            shorpath[src.fi][src.se][x][y]=min(shorpath[src.fi][src.se][x][y],tmp.fi.se);

        for(int i=0;i<v[x][y].size();++i){
            int a=v[x][y][i].fi,b=v[x][y][i].se;
            int yon;
            if(a==x+1 and b==y)
                yon=3;
            else if(a==x-1 and b==y)
                yon=1;
            else if(a==x and b==y+1)
                yon=2;
            else
                yon=4;
            int ekstra=yon-tmp.se;
            if(ekstra<0)
                ekstra+=4;
            q.push(_mp( _mp(_mp(a,b),tmp.fi.se+1+ekstra) ,yon));
        }
        vis[x][y][tmp.se]=tmp.fi.se;
    }
}

void solve(){
    char ar[15][15];
    forr(i,1,11)
        forr(j,1,11)
            cin>>ar[i][j];
    forr(i,1,11)
        forr(j,1,11){
            if(ar[i][j]!='*' and inboard(_mp(i,j+1)) and ar[i][j+1]!='*')
                v[i][j].pb(_mp(i,j+1));
            if(ar[i][j]!='*' and inboard(_mp(i,j-1)) and ar[i][j-1]!='*')
                v[i][j].pb(_mp(i,j-1));
            if(ar[i][j]!='*' and inboard(_mp(i+1,j)) and ar[i+1][j]!='*')
                v[i][j].pb(_mp(i+1,j));
            if(ar[i][j]!='*' and inboard(_mp(i-1,j)) and ar[i-1][j]!='*')
                v[i][j].pb(_mp(i-1,j));
            if(ar[i][j]=='F')
                farmer=_mp(i,j);
            if(ar[i][j]=='C')
                cows.pb(_mp(i,j));
        }
    for(int i=1;i<=10;++i)
        for(int j=1;j<=10;++j)
            bfs(_mp(i,j));    

    
    int mn=0x7fffffff;
    forr(i,1,11)
        forr(j,1,11){
            int sum=0;
            for(auto c:cows){
                int x=c.fi,y=c.se;
                int a=shorpath[x][y][i][j];
                if(a==0 and (i!=x or j!=y)){
                    sum=-1;
                    break;
                }
                sum+=shorpath[x][y][i][j];
            }
            if(sum==-1)
                break;
            int x=farmer.fi,y=farmer.se;
            int a=shorpath[x][y][i][j];
            if(a==0 and (i!=x or j!=y))
                sum=-1;
            else
                sum+=shorpath[x][y][i][j];
            if(sum<mn){
                mn=sum;
                dbg(i),dbg(j),cerr<<endl;
            }
        }
    cout<<mn;
    
        
}