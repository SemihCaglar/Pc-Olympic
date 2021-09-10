#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef vector<int> vi;

vi tree[N];

int n,m;
int answer[N];
int buyukluk[N];
int leaf[N];
int totalleaf;

void dfs(int a,int dad){
    int toplam=buyukluk[a]+totalleaf-leaf[a];
    answer[toplam]=min(answer[toplam],leaf[a]);
    for(int i=0;i<tree[a].size();++i)
        if(tree[a][i]!=dad){
            dfs(tree[a][i],a);
        }    
}

int dfs2(int a,int dad){
    if(tree[a].size()==1&&a!=1){
        buyukluk[a]=1;
        totalleaf++;
        leaf[a]++;
        return 1;
    }
    buyukluk[a]=1;
    for(int i=0;i<tree[a].size();++i){
        if(tree[a][i]!=dad){
            buyukluk[a]+=dfs2(tree[a][i],a);
            leaf[a]+=leaf[tree[a][i]];
        }
    }
    return buyukluk[a];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=2;i<=n;++i){
        int a;
        cin>>a;
        tree[i].push_back(a);
        tree[a].push_back(i);
    }
    for(int i=0;i<=n;++i)
        answer[i]=0x7fffffff;
    dfs2(1,1);
    

    dfs(1,1);
    answer[0]=1;
    for(int i=1;i<=n;++i)
        if(answer[i]==0x7fffffff)
            answer[i]=answer[i-1];   
    
    for(int i=1;i<=n;++i){
        cout<<answer[i]<<' ';
    }
}