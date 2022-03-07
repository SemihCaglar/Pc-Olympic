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
int n,m;
vi v[N][2]; 
ll sum=0;

void f(vi &vv){
    sort(all(vv));
    ll carpi= -((ll)vv.size()-1);
    for(auto i: vv){
        sum+=i*carpi;
        carpi+=2;
    }
}

int main(){
    fast;
    // test();

    cin>>n>>m;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j){
            int c;
            cin>>c;
            v[c][0].pb(i);
            v[c][1].pb(j);
        }    
    for(int i=0;i<N;++i){
        if(!v[i][0].empty())
            f(v[i][0]);
        if(!v[i][1].empty())
            f(v[i][1]);
    }   
    cout<<sum<<"\n"; 

    return 0;
}