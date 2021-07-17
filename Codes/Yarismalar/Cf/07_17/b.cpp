#include<semih/competitive.h>

const int N=25;   

int t,n,m;
int a[N][N];

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                a[i][j]=0;
        a[1][1]=1;
        int x=1,y=2;
        bool state=false;
        while(x!=1 or y!=1){
            if(x==2 and y==m and a[1][m-1]==1){
                state=1;
                goto hey;
            }
            if(x==n and y==m-1 and a[n-1][m]==1){
                state=1;
                goto hey;
            }
            if(x==n-1 and y==1 and a[n][2]==1){
                state=1;
                goto hey;
            }
            if(state and (x!=2 or y!=1))
                a[x][y]=1;
            state=!state;
            hey:
            if(x==1 and y<m)
                y++;
            else if(x<n and y==m)
                x++;
            else if(x==n and y>1)
                y--;
            else
                x--;
        }
    
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j)
                cout<<a[i][j];
            cout<<"\n";
        }
        cout<<"\n";
        
    }    

    return 0;
}