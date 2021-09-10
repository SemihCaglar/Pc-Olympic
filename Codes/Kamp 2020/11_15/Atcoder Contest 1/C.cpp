#include<bits/stdc++.h>
using namespace std;

int adj[10][10];
int n,k,total=0;

int pir[10];
vector<string> v;

void subset(int x,int yol){
    for(;x<=n&&pir[x];++x);
    if(x>n){

        string s="";
        for(int i=1;i<=n;++i)
            s+=(char)(pir[i]+'0');
        
        bool hey=false;
        for(auto i:v)
            if(s==i)
                hey=true;
        if(hey)
            return;    
        if(yol==k)
            total++;
        
        v.push_back(s);
        return;
    }
    if(x==n)
        for(int i=2;i<=n;++i){
            for(int j=0;j<=n;++j){
                if()
            }
        }
    for(int i=2;i<=n;++i){
        if(pir[i]==0&&i!=x){
            pir[i]=x;
            subset(x+1,yol+adj[x][i]);
            pir[i]=0;
        }
    }
}

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>adj[i][j];

    subset(1,0);
    cout<<total;
}