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
    // test;
    fast;
    solve();
    return 0;
}
/*****************************************************************************************/

int t,a,b,k;
int tmp[200005];

ll f(ll x){
    return x*(x-1)/2;
}

void solve(){
    // freopen("/home/semih/Desktop/Pc Olympic/test/test.err","w",stderr);
    cin>>t;
    while(t--){
        cin>>a>>b>>k;
        ll cevap=f(k);
        ll cnt=0;
        for(int i=0;i<k;++i){
            int x;
            cin>>x;
            tmp[x]++;
        }
        for(int i=1;i<=a;++i)
            cnt+=f(tmp[i]);
        for(int i=0;i<=a;++i){
            tmp[i]=0;
        }
        for(int i=0;i<k;++i){
            int x;
            cin>>x;
            tmp[x]++;
        }
        for(int i=1;i<=b;++i)
            cnt+=f(tmp[i]);
        for(int i=0;i<=b;++i){
            tmp[i]=0;
        }
        cout<<cevap-cnt<<'\n';
    }
}