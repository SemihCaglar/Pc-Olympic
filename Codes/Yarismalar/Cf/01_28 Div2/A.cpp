#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define pb push_back
#define _mp make_pair
#define fi first
#define se second
#define sp " "
#define all(v) v.begin(),v.end()
#define forr(i,a,b) for(int i=a;i<b;++i)
#define cfor(i,v) for(auto i=v.begin();i!=v.end();++i)
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define cdbg(v,n) for(int i=0;i<n;++i) cerr<<#v<<"["<<i<<"]:"<<v[i]<<endl
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void filereopen(string name){
    if(name=="/home/semih/Desktop/Pc Olympic/test/test")
        freopen(&*(name+".err").begin(),"w",stderr);
    else if(name=="test")
        name="/home/semih/Desktop/Pc Olympic/test/test";
    freopen(&*(name+".in").begin(),"r",stdin);
    freopen(&*(name+".out").begin(),"w",stdout);
}

#ifndef fname
    #define fname "/home/semih/Desktop/Pc Olympic/test/test"
#endif
#define test filereopen(fname)

void solve();

int main(){
    test;
    fast;
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}
/*****************************************************************************************/

int n;
multiset<ll> st;

bool f(int x){
    if(n!=3){
        if(x%(n-3)==0 and (x/n-3)<=0)
            return true;
    }
    else{
        if(x==0)
            return true;
    }
    if(x%(n+1)==0 and x/(n+1)>=0)
        return true;
    dbg(x);
    return false;
}

void solve(){
    freopen("/home/semih/Desktop/Pc Olympic/test/test.err","w",stderr);
    cin>>n;
    st.clear();
    forr(i,0,2*n){
        int a;
        cin>>a;
        st.insert(a);
    }
    bool flag=true;
    for(auto i:st){
        if(st.count(i)!=2 or f(i)==false){
            flag=false;
            break;
        }
    }
    if(flag)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}