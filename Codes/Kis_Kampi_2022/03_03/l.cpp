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

int n;
map<int,int> mp;

int main(){
    fast;
    // test();

    cin>>n;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        mp[x]++;
    }    
    int ans=0;
    for(int i=0;i<=1e5+5;++i)
        ans=max(ans,mp[i]+mp[i-1]+mp[i-2]);
    cout<<ans<<"\n";

    return 0;
}