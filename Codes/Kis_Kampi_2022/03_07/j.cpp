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

const int MOD=1e9+7;
const int N=1e5+5;
ll a,b;
ll fact[N], inv_fact[N];

ll fp(ll x, ll y){
    if(y==0)
        return 1;
    ll tmp=fp(x,y/2);
    if(y%2==1){
        return tmp*tmp%MOD*x%MOD;
    }
    return tmp*tmp%MOD;
}

int main(){
    fast;
    // test();

    fact[0]=1;
    for(int i=1;i<N;++i){
        fact[i]=fact[i-1]*i%MOD;
    }    
    inv_fact[N-1]=fp(fact[N-1],MOD-2); 
    for(int i=N-2;i>=0;--i){
        inv_fact[i]=inv_fact[i+1]*(i+1)%MOD;
    }        
    inv_fact[0]=1;

    cin>>a>>b;
    ll ans=fact[a];
    ans=ans*inv_fact[b]%MOD;
    ans=ans*inv_fact[a-b]%MOD;
    cout<<ans<<"\n";

    return 0;
}