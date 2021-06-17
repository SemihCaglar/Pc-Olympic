#include<bits/stdc++.h>
using namespace std;
const int N=105;

char mine[N][N];
int n,m,cnt;

bool in(int i,int j){
    if(i>=0 and i<n and j>=0 and j<m)
        return true;
    return false;
}

void fill(int i,int j){
    for(int a=0;a<3;++a)
        for(int b=0;b<3;++b){
            int bir=a==0?-1:a==1?0:1;
            int iki=b==0?-1:b==1?0:1;
            bir+=i,iki+=j;
            if(mine[bir][iki]<'*' and in(bir,iki))
                mine[bir][iki]++;
        }
}

int main(){
    while(cin>>n>>m,n||m){
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j){
                cin>>mine[i][j];
                if(mine[i][j]=='.')
                    mine[i][j]=0;
            }
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                if(mine[i][j]=='*')
                    fill(i,j);
        if(cnt)
            cout<<'\n';
        cout<<"Field #"<<++cnt<<":\n";
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(mine[i][j]=='*')
                    cout<<"*";
                else
                    cout<<(int)mine[i][j];
            }
            cout<<'\n';
        }
        
    }
}