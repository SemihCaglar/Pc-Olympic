#include<semih/competitive.h>

int x=0,y=0,z=0;

void artir(int c){
    x=(x+c)%15,y=(y+c)%28,z=(z+c)%19;
    if(x==0) x=15;
    if(y==0) y=28;
    if(z==0) z=19;
}

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int cnt=b;
    artir(b);
    while(true){
        if(x==a and y==b and z==c){
            cout<<cnt;
            return;
        }
        artir(28);
        cnt+=28;
    }
}

int main(){
    test;
    fast;

    int t=1;
    // cin>>t;
    while(t--)
        solve();
    return 0;
}