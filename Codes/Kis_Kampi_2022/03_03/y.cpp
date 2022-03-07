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

#define int long long

const int MOD=1e9+7;

int fp(int x){
    if(x==0)
        return 1;
    int tmp=fp(x/2);
    if(x%2==1)
        return tmp*tmp%MOD*2%MOD;
    return tmp*tmp%MOD;

}

map<int,int> dp;

int f(int x){
    if(x==1)
        return 1;
    if(dp.count(x))
        return dp[x];
    int sum=fp(x-1);
    for(int i=2;i*i<=x;++i){
        if(x%i)
            continue;
        sum-=f(i);
        sum%=MOD;
        sum+=MOD;
        sum%=MOD;
        if(i*i!=x)
            sum-=f(x/i),sum%=MOD,sum+=MOD,sum%=MOD;
    }
    sum-=1;
    sum%=MOD;
    sum+=MOD;
    sum%=MOD;
    return dp[x]=sum;
}

int x,y;

int32_t main(){
    fast;
    // test();

    cin>>x>>y;
    if(y%x){
        cout<<0<<"\n";
        return 0;
    }
    cout<<f(y/x)<<"\n";

    return 0;
}