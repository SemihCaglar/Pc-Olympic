#include<semih/competitive.h>

int m;
multiset<int> v[505];
vi path;

void dfs(int node){
    while(!v[node].empty()){
        int next=*v[node].begin();
        v[node].erase(v[node].find(next));
        v[next].erase(v[next].find(node));
        dfs(next);
    }
    path.pb(node);
}

int main(){
    fast;
    // test("fence");

    cin>>m;
    forr(i,0,m){
        int a,b;
        cin>>a>>b;
        v[a].insert(b);
        v[b].insert(a);
    }

    int i; 
    for(i=1;i<=500;++i)
        if(v[i].size()%2==1)
            break;
    if(i>500)
        for(i=1;i<=500;++i)
            if(v[i].size())
                break;

    dfs(i); 
    reverse(all(path)); 

    for(auto j:path)
        cout<<j<<'\n';

    return 0;
}