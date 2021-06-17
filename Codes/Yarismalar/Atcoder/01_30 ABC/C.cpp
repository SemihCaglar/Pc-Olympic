#include<semih/competitive.h>

int n,m,k;
ii cond[105];
ii choice[20];
multiset<int> st;
int mx=-1;

void check(){
    int cnt=0;
    forr(i,0,m){
        if(st.count(cond[i].fi) and st.count(cond[i].se))
            cnt++;
    }
    mx=max(mx,cnt);
}

void subset(int x){
    if(x==k){
        check();
        return;
    }
    st.insert(choice[x].fi);
    subset(x+1);
    st.erase(st.find(choice[x].fi));
    st.insert(choice[x].se);
    subset(x+1);
    st.erase(st.find(choice[x].se));
}

void solve(){
    freopen("/home/semih/Desktop/Pc Olympic/test/test.err","w",stderr);
    cin>>n>>m;
    forr(i,0,m){
        int a,b;
        cin>>a>>b;
        cond[i]=ii(a,b);
    }
    cin>>k;
    forr(i,0,k){
        int a,b;
        cin>>a>>b;
        choice[i]=ii(a,b);
    }
    subset(0);
    cout<<mx<<'\n';
}