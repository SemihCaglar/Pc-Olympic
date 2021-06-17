#include<semih/competitive.h>

const int N=105;

int n;
int perc[N][N];
int inp[N][N];
int secim;
bool own[N][N];

void solve(){
    cin>>n;
    forr(i,0,n){
        int a,b,p;
        cin>>a>>b>>p;
        inp[a][b]=p;
    }
    bool flag=true;
    n=100;
    while(flag){
        flag=false;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j){
                if(i==j)
                    continue;
                secim=perc[i][j]+inp[i][j];
                if( secim>50 and own[i][j]==false){
                    own[i][j]=true;
                    flag=true;
                    for (int k = 1; k <= n; ++k){
                        if (k == i or k == j)
                            continue;
                        secim = inp[j][k];
                        if (own[i][k] == false)
                            perc[i][k] += secim;
                    }
                }
            }
    }
    for(int i=1;i<=100;++i)
        for(int j=1;j<=100;++j)
            if(own[i][j])
                cout<<i<<sp<<j<<endl;
}