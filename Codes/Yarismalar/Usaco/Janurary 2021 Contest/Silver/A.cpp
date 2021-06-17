#include<bits/stdc++.h>
using namespace std;
#define test freopen("/home/semih/Desktop/Pc Olympic/test/test.in","r",stdin);freopen("/home/semih/Desktop/Pc Olympic/test/test.out","w",stdout)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int N=2e5+5;

int n,k;
int dad[N];
int Size[N];
int location[N];
pair<int,int> input[N];
set<int> neblm[N];
int nevar[N];

int find(int x){
    if(x==dad[x])
        return x;
    return dad[x]=find(dad[x]);
}

void unio(int a,int b){
    if(find(a)!=find(b)){
        dad[find(a)]=dad[find(b)];
        Size[b]+=Size[a];
    }
}

int main(){
    fast;
    test;

    cin>>n>>k;
    for(int i=0;i<n;++i)
        dad[i]=i,Size[i]=1,location[i]=i;
    for(int i=0;i<k;++i){
        int a,b;
        cin>>a>>b;
        a--,b--;
        input[i]=make_pair(a,b);
        swap(location[a],location[b]);
    }
    for(int i=0;i<n;++i)
        unio(i,location[i]),cout<<location[i]<<" ncjcd\n";
    for(int i=0;i<n;++i)
        nevar[i]=i;
    for(int i=0;i<k;++i){
        int a=input[i].first,b=input[i].second;
        if (find(nevar[a]) != find(b))
            neblm[find(nevar[a])].insert(b);
        if (find(nevar[b]) != find(a))
            neblm[find(nevar[b])].insert(a);
        swap(nevar[a],nevar[b]);
    }
    for(int i=0;i<n;++i){
        cout<<Size[find(i)]<<' '<<neblm[find(i)].size()<<'\n';
    }
    
}