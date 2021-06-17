// https://codeforces.com/contest/1093/problem/D
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
const int MOD=998244353;
typedef unsigned long long int ulli;

vector<int>v[300999];
void clear(int n){
    for(int i=0;i<n+3;++i)
        v[i].clear();
}

void f(){

    int n,m;
    scanf("%d%d",&n,&m);
    ulli answer=1LL;
    bool used[n+999];
    bool sign[n+999];
    queue<int> nodes;    
    for(int i=0;i<m;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;++i){
        used[i]=0;
        sign[i]=0;
        nodes.push(i);  
    }    
    while(!nodes.empty()){
        int a=nodes.front();
        int tek=0,cift=0;
        nodes.pop();
        if(used[a])
            continue;
        queue<int> bfs;
        bfs.push(a);
        used[a]=1;
        sign[a]=0;
        ++cift;    
        while(!bfs.empty()){
            int tmp=bfs.front();
            bfs.pop();
            for(int i=0;i<v[tmp].size();++i){
                if(used[v[tmp][i]]){
                    if(sign[tmp]!=1-sign[v[tmp][i]]){
                      printf("             0\n");
                      clear(n);
                      return;
                    }
                }        
                else{
                    bool hey=1-sign[tmp];
                    if(hey)
                        ++tek;
                    else
                        ++cift; 
                    sign[v[tmp][i]]=hey;
                    used[v[tmp][i]]=1;
                    bfs.push(v[tmp][i]);    
                }          
            }
        }
        ulli ans1 = 1LL, ans2 = 1LL ;
        for (int i = 0; i < tek; ++i)
            ans1 = ans1 * 2 % MOD;
        for (int i = 0; i < cift; ++i)
            ans2 = ans2 * 2 % MOD;
        ans1 = (ans1 + ans2) % MOD;
        answer=answer*ans1%MOD;
    }   
    printf("             %llu\n",answer);
    clear(n);
    return;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--)
        f();
    getchar();
    getchar();    
}