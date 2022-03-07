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
#define all(v) v.begin(),v.end()
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define cdbg(v,n) for(int i=0;i<n;++i) cerr<<#v<<"["<<i<<"]:"<<v[i]<<endl
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void test(string name="/home/ecr/Desktop/pc-olympic/test/test"){
    freopen(&*(name+".in").begin(),"r",stdin);
    freopen(&*(name+".out").begin(),"w",stdout);
}
/*****************************************************************************************/

const int N=1e5+5;
const int MOD=1e9+7;
int n;
vi g[N];

ll dp[N][2];

int f(int node, bool opt, int dad){ // opt: 0 ise devami gelmeli, 1 ise np. 
    ll &ref=dp[node][opt];
    if(ref!=-1)
        return ref;

    if(opt==false){
        ll carpi1=1;
        for(auto to: g[node])
            if(to!=dad){
                carpi1*=f(to,0, node)+f(to,1, node);
                carpi1%=MOD;
            }   
        ll carpi2=1;
        for(auto to: g[node])
            if(to!=dad){
                carpi2*=f(to,0, node);
                carpi2%=MOD;
            }
        return ref = (((carpi1-carpi2)%MOD)+MOD)%MOD;   
    }
    else{
        ll carpi1=1;
        for(auto to: g[node])
            if(to!=dad){
                carpi1*=f(to,0, node)+f(to,1, node);
                carpi1%=MOD;
            }   
        return ref=carpi1;
    }
}

int main(){
    fast;
    // test();

    cin>>n;
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }    
    for(int i=0;i<=n;++i)
        dp[i][0]=dp[i][1]=-1;
    cout<<2LL*f(1,0, -1)%MOD<<"\n";

    return 0;
}