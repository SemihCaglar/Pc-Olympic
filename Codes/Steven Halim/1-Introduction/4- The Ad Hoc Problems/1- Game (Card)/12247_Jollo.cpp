#include<bits/stdc++.h>
using namespace std;

int kiz[3],erkek[2];

bool vis[55];

int f(int x){
    for(;vis[x] and x<=52;x++);
    return x;
}

int main(){
    while(cin>>kiz[0]>>kiz[1]>>kiz[2]>>erkek[0]>>erkek[1] , kiz[0]){
        memset(vis,0,sizeof(vis));
        sort(kiz,kiz+3); sort(erkek,erkek+2);
        vis[kiz[0]]=vis[kiz[1]]=vis[kiz[2]]=vis[erkek[0]]=vis[erkek[1]]=true;
        if(erkek[1]>kiz[2]){
            if(erkek[0]<kiz[0]){
                int ans=f(kiz[2]);
                ans==53?cout<<-1:cout<<ans;
            }
            else if(erkek[0]>kiz[1] and erkek[0]<kiz[2]){
                int ans=f(kiz[1]);
                ans==53?cout<<-1:cout<<ans;
            }
            else if(erkek[0]>kiz[0] and erkek[0]<kiz[1]){
                int ans=f(kiz[2]);
                ans==53?cout<<-1:cout<<ans;
            }
            else if(erkek[0]>kiz[2]){
                int ans=f(1);
                ans==53?cout<<-1:cout<<ans;
            }
        }
        else if(erkek[0]<kiz[2] and erkek[0]>kiz[1] and erkek[1]<kiz[2] and erkek[1]>kiz[1]){
            int ans=f(kiz[1]);
            ans==53?cout<<-1:cout<<ans;
        }
        else{
            cout<<-1;
        }
        cout<<'\n';

    }
}

