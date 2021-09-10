#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

vector<int> v[N];
bool vis1[N],vis2[N];
int n;

int enuzak[N],uzaklik[N]; // en uzak nokta,uzaklik.
int root;

void dfs(int x,int dad){
    if(v[x].size()==1 and x!=1){
        uzaklik[x]=0;
        enuzak[x]=x;
        return;
    }
    int mx=-1;
    int uzaknokta,prevhedef;
    for(int i=0;i<v[x].size();++i){
        int hedef=v[x][i];
        if(hedef!=dad){
            dfs(hedef,x);
            if(uzaklik[hedef]>mx){
                if(mx!=-1){
                    vis1[prevhedef]=false;
                }   
                mx=uzaklik[hedef];
                uzaknokta=enuzak[hedef];
                vis1[hedef]=true;
                prevhedef=hedef;
            }   
        }  
    }
    uzaklik[x]=mx+1;
    enuzak[x]=uzaknokta;
}

void dfs2(int x){ 
    vis2[x]=true;
    if(v[x].size()==1 and x!=root){
        uzaklik[x]=1-vis1[x];
        enuzak[x]=x;
        return;
    }
    int uzaknokta=0,mx=0;
    for(int i=0;i<v[x].size();++i){
        int hedef=v[x][i];
        if(vis2[hedef])
            continue;
        dfs2(hedef);
        if(uzaklik[hedef]>mx){
            mx=uzaklik[hedef];
            uzaknokta=enuzak[hedef];
        }
    }
    uzaklik[x]=mx+(1-vis1[x]);
    enuzak[x]=uzaknokta;
}

int main(){
    cin>>n;
    for(int i=1;i<n;++i){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    //cout<<endl<<endl;
    dfs(1,1);
    vis1[1]=true;
    root=enuzak[1];
    int toplamkenar=uzaklik[1];
    //cout<<"**"<<root<<endl;
    dfs2(root);
    // cout<<enuzak[root]<<" "<<uzaklik[root]<<endl;
    // for(int i=1;i<=n;++i){
    //     cout<<i<<": "<<enuzak[i]<<" "<<uzaklik[i]<<endl;
    // }
    int ucuncu;
    if(uzaklik[root]==0){
        for(int i=2;i<=n;++i)
            if(i!=root){
                ucuncu=i;
                break;
            }
    }
    else{
        ucuncu=enuzak[root];
        toplamkenar+=uzaklik[root];
    }
    cout<<toplamkenar<<'\n'<<1<<' '<<root<<' '<<ucuncu;
    

}