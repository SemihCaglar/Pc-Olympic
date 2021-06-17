#include<bits/stdc++.h>
using namespace std;

int n;
int mx=-1;
int a[10][10];
bool vis[10][10];

void check(){
    int sum=0;
    for(int i=0;i+1<n;++i)
        for(int j=0;j+1<n;++j){
            int cnt=0;
            if(vis[i][j]) cnt++;
            if(vis[i][j+1]) cnt++;
            if(vis[i+1][j]) cnt++;
            if(vis[i+1][j+1]) cnt++;
            if(cnt!=2)
                return;
        }
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            if(vis[i][j])
                sum+=a[i][j];
    mx=max(mx,sum);
}

void subset(int x){
    if(x==n*n){
        check();
        return;
    }
    vis[x/n][x%n]=0;
    subset(x+1);
    vis[x/n][x%n]=1;
    subset(x+1);
}

int main(){
    cin>>n;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cin>>a[i][j];
    subset(0);
    cout<<mx<<endl;
}