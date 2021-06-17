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

/*********************************************************************************************************/


typedef long double ld;
int h,down,perc;
ld up;

void solve(){
    ld init=0,n=up;
    int cnt=1;
    while(true){
        init+=up;
        if(init>h){
            cout<<"success on day "<<cnt<<'\n';
            return;
        }
        init-=down;
        if(init<0){
            cout<<"failure on day "<<cnt<<'\n';
            return;
        }
        up-=(n*perc)/100.0;
        if(up<0)
            up=0;
        cnt++;
    }
}

int main(){
    //test;
    fast;

    int t=1;
    // cin>>t;
    while(cin>>h>>up>>down>>perc, h)
        solve();
    return 0;
}