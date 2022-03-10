#include<semih/competitive.h>

const int N=5e2+5;
int n,k;
vi g[N];
int dp[N][505];
int ata[N];

int f(int node,int dad,int h){ // node'un h asagisindaki nodelarin sayisi.
    int &ref=dp[node][h];
    if(ref)
        return ref;
    if(h==0)
        return ref=1;
    int sum=0;
    for(auto to: g[node]){
        if(to==dad){
            ata[node]=to;
            continue;
        }
        sum+=f(to,node,h-1);
    }
    return ref=sum;
}

int ff(int node, int dad, int d){ // uzaklik d olacak.
    int carpi1,carpi2,carpi3;
    carpi1=carpi2=carpi3=1;
    for(int i=0;i<=d-2;++i){
        int biri=i, digeri=d-2-i;
        for(auto to: g[node]){
            if(to==dad)
                continue;
            carpi1*=ff(to,node,biri)+ff(to,node,digeri);
            carpi2*=ff(to,node,biri);
            carpi3*=ff(to,node,digeri);
        }
    }
    return carpi1-carpi2-carpi3;
}

int main(){
    fast;
    test();

    cin>>n>>k;
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }    
    for(int i=0;i<=n;++i)
        f(1,-1,i);
    int sum=0;
    for(int i=1;i<=n;++i){
        for(int j=0;j<=k;++j){
            if(2*j==k){
                int tmp=dp[i][j];
                sum+=tmp*(tmp-1);
            }
            else{
                int tmp=k-j;
                sum+=dp[i][j]*dp[i][tmp];
            }
        }
    }
    cout<<sum/2<<"\n";    

    return 0;
}