/*
ID: semihca1
TASK: wormhole
LANG: C++                 
*/
#define isim  "wormhole"

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
#define fi first
#define se second

int result=0;
int n;
ii coor[20];
int saginda[20]; 
int partner[20];

bool check(){
    for(int i=1;i<=n;++i){
        bool vis[20];
        for(int i=0;i<20;++i)
            vis[i]=false;
        
        int tmp=i;
        while(true){
            if(vis[tmp])
                return true;
            vis[tmp]=true;
            tmp=partner[tmp];
            tmp=saginda[tmp];
            if(tmp==0)
                break;
        }
    }
    return false;
}

void subset(int x){
    for(;x<=n&&partner[x];++x);

    if(x>n){
        result+=check();
        return;
    }
    for(int j=x+1;j<=n;++j){
        if(partner[j]==false){
            partner[x]=j;
            partner[j]=x;
            subset(x+1);
            partner[x]=partner[j]=false;
        }
    }
    return;
}

int main() {
    //freopen( &*(string(isim)+".in").begin() , "r" , stdin );
    //freopen( &*(string(isim)+".out").begin() , "w" , stdout );
    cin>>n;
    for(int i=1;i<=n;++i){
        int a,b;
        cin>>a>>b;
        coor[i]=ii(a,b);
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(coor[i].se==coor[j].se&&coor[i].fi<coor[j].fi){
                if(saginda[i]==0)
                    saginda[i]=j;
                else if(coor[j].fi<coor[saginda[i]].fi)
                    saginda[i]=j;
            }
        }
    }

    subset(1);
    cout<<result<<endl;
    
}    