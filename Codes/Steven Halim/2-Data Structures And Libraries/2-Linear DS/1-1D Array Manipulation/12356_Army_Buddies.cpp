#include<semih/competitive.h>
const int N=1e5+5;
int n,m;

void solve(){
    set<int> st;
    forr(i,1,n+1)
        st.insert(i);
    forr(i,0,m){
        int l,r;
        cin>>l>>r;
        forr(j,l,r+1)
            st.erase(j);
        set<int>::iterator it;
        if(it=st.lower_bound(l),it!=st.begin())
            it--,cout<<*it<<sp;
        else
            cout<<"* ";
        if(it=st.upper_bound(r),it!=st.end())
            cout<<*it;
        else
            cout<<"*";
        cout<<'\n';
    }
}

int main(){
    test;
    fast;

    int t=1;
    // cin>>t;
    while(cin>>n>>m,n or m){
        solve();
        cout<<"-\n";
    }
    return 0;
}