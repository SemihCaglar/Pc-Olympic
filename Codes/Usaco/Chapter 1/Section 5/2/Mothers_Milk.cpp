/*
ID: semihca1
TASK: milk3
LANG: C++                 
*/
#define isim  "milk3"

#include<bits/stdc++.h>
using namespace std;

bool varmi[22];
int A,B,C;
bool vis[22][22][22];

void dfs(int a,int b,int c){
    if(a==0)
        varmi[c]=true;
    if(vis[a][b][c])
        return;
    vis[a][b][c]=true;
    int tmp=a-(B-b);
    if(tmp<0)
        dfs(0,b+a,c);
    else
        dfs(tmp,B,c);

    tmp=a-(C-c);
    if(tmp<0)
        dfs(0,b,c+a);
    else
        dfs(tmp,b,C);

    tmp=b-(A-a);
    if(tmp<0)
        dfs(a+b,0,c);
    else
        dfs(A,tmp,c);

    tmp=b-(C-c);
    if(tmp<0)
        dfs(a,0,c+b);
    else
        dfs(a,tmp,C);

    tmp=c-(A-a);
    if(tmp<0)
        dfs(a+c,b,0);
    else
        dfs(A,b,tmp);

    tmp=c-(B-b);
    if(tmp<0)
        dfs(a,b+c,0);
    else
        dfs(a,B,tmp);
}

int main() {
    //freopen( &*(string(isim)+".in").begin() , "r" , stdin );
    //freopen( &*(string(isim)+".out").begin() , "w" , stdout );
    cin>>A>>B>>C;
    dfs(0,0,C);
    bool ilk=false;
    for(int i=0;i<22;++i)
        if(varmi[i]){
            if(ilk)
                cout<<' ';
            ilk=true;
            cout<<i;
        }
    cout<<endl;
}    