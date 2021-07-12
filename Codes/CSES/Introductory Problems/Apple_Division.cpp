#include<semih/competitive.h>

bool pos[25];
int n,a[25];
ll mn=LONG_LONG_MAX;


void dfs(int x){
    if(x==n){
        ll suma=0,sumb=0;
        for(int i=0;i<n;++i){
            if(pos[i])
                suma+=a[i];
            else
                sumb+=a[i];
        }
        mn=min(mn,abs(suma-sumb));
        return;
    }
    dfs(x+1);
    pos[x]=1;
    dfs(x+1);
    pos[x]=0;
}

int main(){
    fast;
    // test();

    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    
    dfs(0);    
    cout<<mn<<"\n";

    return 0;
}