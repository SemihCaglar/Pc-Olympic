#include<semih/competitive.h>

const int N=32;
const int INF=0x7fffffff;
int n,m;
ii king;
vii knights;
int dist[N][N][N][N][2];

int pickup(ii coor){
    return min( abs(king.fi-coor.fi) , abs(king.se-coor.se) );
}

bool intable(int x,int y){
    if(x<=m and x>=1 and y<=n and y>=1)
        return true;
    return false;
}

vii new_coor(ii coor){
    vii ans;
    for(int i=-1;i!=3;i+=2)
        for(int j=-1;j!=3;j+=2)
            for(int bir=0;bir<2;++bir){
                int x,y;
                if(bir){
                    x=i*2;
                    y=j*1;
                }
                else{
                    x=i*1;
                    y=j*2;
                }
                if(intable(coor.fi+x,coor.se+y)){
                    ans.pb({coor.fi+x,coor.se+y});        
                }
            }
    return ans;
}

int main(){
    fast;
    // test("camelot");
    test();

    cin>>n>>m;
    {
        char x;
        int y;
        cin>>x>>y;
        king={x-'A'+1,y};

        while(cin>>x>>y)
            knights.pb({x-'A'+1,y});
    }  
    if(knights.empty()){
        cout<<"0\n";
        return 0;
    }

    for(int i=0;i<=m;++i)
        for(int j=0;j<=n;++j)
            for(int k=0;k<=m;++k)
                for(int neblm=0;neblm<=n;++neblm)
                    dist[i][j][k][neblm][0]=dist[i][j][k][neblm][1]=INF;

    for(int at_x=1;at_x<=m;++at_x)
        for(int at_y=1;at_y<=n;++at_y){

            typedef pair <ii,int> iii;
            queue<iii> q; // ( (x,y),mesafe )
            q.push({{at_x,at_y},0});

            while(!q.empty()){

                iii tmp=q.front();
                q.pop();

                ii coordinate=tmp.fi;
                int mesafe=tmp.se;

                if( dist[at_x][at_y][coordinate.fi][coordinate.se][0]==INF ){
                    dist[at_x][at_y][coordinate.fi][coordinate.se][0] = mesafe;
                    vii olasi=new_coor(coordinate);
                    for(ii i: olasi)
                        q.push({i,mesafe+1});
                }

            }        
    }
    
    for(int at_x=1;at_x<=m;++at_x)
        for(int at_y=1;at_y<=n;++at_y){
            for(int hedef_x=1;hedef_x<=m;++hedef_x)
                for(int hedef_y=1;hedef_y<=n;++hedef_y){
                    int mn=INF;
                    for(int durak_x=max(king.fi-6,1);durak_x<=min(king.fi+6,m);++durak_x)
                        for(int durak_y=max(king.se-6,1);durak_y<=min(king.se+6,n);++durak_y){
                            int maybe = dist[at_x][at_y][durak_x][durak_y][0] + pickup({durak_x,durak_y}) + dist[durak_x][durak_y][hedef_x][hedef_y][0] ;
                            mn=min(mn,maybe);   
                        }
                    dist[at_x][at_y][hedef_x][hedef_y][1]=mn;
                }
        }

    int ans=INF;
    for(int x=1;x<=m;++x)
        for(int y=1;y<=n;++y){
            int sum=0;
            for(ii at: knights)
                sum+=dist[at.fi][at.se][x][y][0];
            int mn=INF;
            for(ii at: knights)
                mn=min(mn, dist[at.fi][at.se][x][y][1] - dist[at.fi][at.se][x][y][0] );
            sum+=mn;
            ans=min(ans,sum);
        }
    cout<<ans<<"\n";

    return 0;
}