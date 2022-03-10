#include<semih/competitive.h>

const int MOD=998244353;
const int N=405;

int n,m;
bool good[N][N];

int f(int l, int r){
    if(r<l)
        return 1;
    if(l==r)
        return 0;
    int sum=0;
    for(int i=l+1;i<=r;++i){
        if(good[l][i]){
            sum+=2*f(l+1,i-1)*f(i+1,r);
        }
    }    
    return sum;
}

int main(){
    fast;
    // test();

    cin>>n>>m;
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        good[u][v]=good[v][u]=true;
    }
    cout<<f(1,2*n);    

    return 0;
}