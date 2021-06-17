#include<semih/competitive.h>

const int N=3e3+5;
int ar[N];
int n;
bool vis[N];

void solve(){
    forr(i,0,n)
        vis[i]=0;
    forr(i,0,n)
        cin>>ar[i];
    forr(i,0,n-1)
        vis[abs(ar[i]-ar[i+1])]=true;
    forr(i,1,n)
        if(vis[i]==false){
            cout<<"Not jolly\n";
            return;
        }
    cout<<"Jolly\n";
}

int main(){
    test;
    fast;

    int t=1;
    // cin>>t;
    while(cin>>n)
        solve();
    return 0;
}