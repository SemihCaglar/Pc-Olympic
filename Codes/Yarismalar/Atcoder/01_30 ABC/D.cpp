#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
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
    // test;
    fast;
    solve();
    return 0;
}
/*****************************************************************************************/

ll n;
map<ll,ll> carpan;
map<ll,bool> vis;
ll cnt;

bool valid(ll x);

void f(ll x){
    ll N=x;
    for(ll i=2;i*i<=N;++i){
        while(x%i==0){
            carpan[i]++;
            x/=i;
        }
    }
    if(x!=1)
        carpan[x]++;
}

void subset(ll num,ll deg){
    if(deg==carpan.size()){
        // dbg(num);
        if(vis[num])
            return;
        if(valid(num))
            cnt++;
        vis[num]=true;
        return;
    }
    auto it=carpan.begin();
    forr(i,0,deg)
        it++;
    ii ref=*it;
    forr(i,0,ref.se){
        subset(num,deg+1);
        num*=ref.fi;
    }
    subset(num,deg+1);
}

bool valid(ll x){
    // if((n*2)%x)
    //     return false;
    ll tmp=(n*2)/x;
    return (tmp-x+1)%2==0;
}

void solve(){
    // freopen("/home/semih/Desktop/Pc Olympic/test/test.err","w",stderr);
    cin>>n;
    f(n*2);
    // for(auto i:carpan)
    //     cout<<i.fi<<sp<<i.se<<endl;
    subset(1,0);
    cout<<cnt<<'\n';
}