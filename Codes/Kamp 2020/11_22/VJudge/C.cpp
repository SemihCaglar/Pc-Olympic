#include<bits/stdc++.h>
using namespace std;
const int N=25;

int n,m;
bool yatay[N],dikey[N];
bool mark[N][N];

void dfs(int i,int j){
    mark[i][j]=true;
    if(yatay[i]==1){
        if(j<m-1 and !mark[i][j+1])
            dfs(i,j+1);
    }
    if(yatay[i]==0){
        if(j>0 and !mark[i][j-1])
            dfs(i,j-1);
    }
    
    if(dikey[j]==1){
        if(i<n-1 && !mark[i+1][j])
            dfs(i+1,j);
    }
    if(dikey[i]==0){
        if(i>0 and !mark[i-1][j])
            dfs(i-1,j);
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;++i){
        char a;
        cin>>a;
        if(a=='>')
            yatay[i]=true;
        else
            yatay[i]=false;
    }

    for(int i=0;i<m;++i){
        char a;
        cin>>a;
        if(a=='v')
            dikey[i]=true;
        else
            dikey[i]=false;
    }
    bool flag=false;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            for(int a=0;a<n;++a)
                for(int b=0;b<m;++b)
                    mark[a][b]=0;
            dfs(i,j);
            for(int a=0;a<n&&!flag;++a)
                for(int b=0;b<m;++b)
                    if(mark[a][b]==0){
                        flag=true;
                        cout<<"Hey "<<a<<" "<<b<<endl;
                        break;
                    }
            if(flag){
                cout<<"NO "<<i<<" "<<j;
                return 0;
            }
        }
    }
    cout<<"YES";

}