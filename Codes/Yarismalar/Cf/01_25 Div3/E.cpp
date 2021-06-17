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

int t,k,n;
const int MOD=1e9+7;
ll dp[1005][1005];

ll comb(int a,int b){
    if(a==b or b==0)
        return 1;
    if(dp[a][b]!=-1)
        return dp[a][b];
    return dp[a][b]=(comb(a-1,b-1)+comb(a-1,b))%MOD;
}


void solve(){
    // freopen("/home/semih/Desktop/Pc Olympic/test/test.err","w",stderr);
    for(int i=0;i<=1004;++i)
        for(int j=0;j<=1004;++j)
            dp[i][j]=-1;
    cin>>t;
    while(t--){
        cin>>n>>k;
        multiset<int> a;
        for(int i=0;i<n;++i){
            int x;
            cin >> x;
            a.insert(x);
        }
        while(true){
            int neblm=a.count(*a.rbegin());
            if(k>neblm){
                a.erase(*a.rbegin());
                k-=neblm;
            }
            else{
                cout<<comb(neblm,k)<<'\n';
                break;
            }

        }
    }
}