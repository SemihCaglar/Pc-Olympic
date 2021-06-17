// https://codeforces.com/contest/1063/problem/B
#include<iostream>
#include<queue>
using namespace std;
const int N=2e3+100;
bool labyrinth[N][N];
bool marked[N][N];
int sagsol1[N][N][2]; //min sag
int sagsol2[N][N][2]; // min sol
bool ok[N][N];

int main(){

    int n,m,r,c;
    cin>>n>>m>>r>>c;
    unsigned long long int x,y;
    cin>>x>>y;
    for(int i=1;i<=n;++i){
        string satir;
        cin>>satir;
        for(int j=1;j<=m;++j){
            char a;
            a=satir[j-1];
            labyrinth[i][j]= a=='*'?false:true;
        }
    }    
    typedef struct cell{
        int x,y;
        unsigned long long int sag,sol;
    }cell;

    long long int cnt=0;
    
    queue<cell> bfs;
    cell tmp={r,c,0,0};
    bfs.push(tmp);
    
    while(!bfs.empty()){
        tmp=bfs.front();
        bfs.pop();
        if(marked[tmp.x][tmp.y]){
            bool hey=false;
            if(tmp.sag<sagsol1[tmp.x][tmp.y][0]){
                sagsol1[tmp.x][tmp.y][0]=tmp.sag;
                sagsol1[tmp.x][tmp.y][1]=tmp.sol;
                hey=true;
            }
            if(tmp.sol<sagsol2[tmp.x][tmp.y][1]){
                sagsol2[tmp.x][tmp.y][0]=tmp.sag;
                sagsol2[tmp.x][tmp.y][1]=tmp.sol;
                hey=true;
            }    
            if(!hey)
                continue;
        }
        else{
            sagsol1[tmp.x][tmp.y][0]=tmp.sag;
            sagsol1[tmp.x][tmp.y][1]=tmp.sol;
            sagsol2[tmp.x][tmp.y][0]=tmp.sag;
            sagsol2[tmp.x][tmp.y][1]=tmp.sol;    
        }
        if(tmp.sol<=x&&tmp.sag<=y&&!ok[tmp.x][tmp.y]){
            ++cnt;
            ok[tmp.x][tmp.y]=true;
        }    

        if(tmp.x+1<=n&&labyrinth[tmp.x+1][tmp.y]){
            cell ust={tmp.x+1,tmp.y,tmp.sag,tmp.sol};
            bfs.push(ust);
        }        
        if(tmp.x-1>=1&&labyrinth[tmp.x-1][tmp.y]){
            cell alt={tmp.x-1,tmp.y,tmp.sag,tmp.sol};
            bfs.push(alt);
        }        
        if(tmp.y+1<=m&&labyrinth[tmp.x][tmp.y+1]){
            cell sag={tmp.x,tmp.y+1,tmp.sag+1LL,tmp.sol};
            bfs.push(sag);
        }        
        if(tmp.y-1>=1&&labyrinth[tmp.x][tmp.y-1]){
            cell sol={tmp.x,tmp.y-1,tmp.sag,tmp.sol+1LL};
            bfs.push(sol);
        }        
    
        marked[tmp.x][tmp.y]=true;
    
    }
    cout<<cnt;
     
}