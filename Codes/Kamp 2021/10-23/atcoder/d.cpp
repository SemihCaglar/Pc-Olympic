#include<semih/competitive.h>

int m;
vi g[10];
vi parca;
map<vi,bool> mp;

int tek(vi v){
    set<int> st;
    for(auto i: v)
        st.insert(i);
    for(int i=1;i<=9;++i)
        if(st.count(i)==0)
            return i;
    return 0;
}

bool check(vi v){
    for(int i=1;i<=8;++i)
        if(v[i-1]!=i)
            return false;
    return true;
}

int hangisi(vi v,int num){
    for(int i=1;i<=8;++i)
        if(v[i-1]==num)
            return i;
    return 0;
}

int f(vi v){
    queue<pair<vi,int>> q; // {dizi,cost}

    q.push({v,0});
    while(!q.empty()){
        vi tmp=q.front().fi;
        int cost=q.front().se;
        if(cost>1e4)
            return -1;
        q.pop();
        if(mp[tmp])
            continue;
        mp[tmp]=true;
        if(check(tmp))
            return cost;
        
        int bos_olan=tek(tmp);
        for(auto i:g[bos_olan]){
            vi next=tmp;
            int ordaki=hangisi(tmp,i);
            next[ordaki-1]=bos_olan;
            q.push({next,cost+1});
        }
    }
    return -1;
}

int main(){
    fast;
    // test();

    cin>>m;
    for(int i=0;i<m;++i){
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }    
    parca.resize(8);
    for(int i=0;i<9;++i)    
        cin>>parca[i];

    cout<<f(parca)<<"\n";    

    return 0;
}