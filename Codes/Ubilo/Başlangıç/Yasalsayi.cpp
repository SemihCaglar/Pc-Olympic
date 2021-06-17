#define fname  "asal"

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
    if(name=="/mnt/c/Users/semih çağlar/Desktop/Pc Olympic/test")
        freopen(&*(string(name)+".err").begin(),"w",stderr);
    else if(name=="test")
        name="/mnt/c/Users/semih çağlar/Desktop/Pc Olympic/test";
    freopen(&*(string(name)+".gir").begin(),"r",stdin);
    freopen(&*(string(name)+".cik").begin(),"w",stdout);
}

#ifndef fname
    #define fname "/mnt/c/Users/semih çağlar/Desktop/Pc Olympic/test"
#endif
#define test filereopen(string(fname))

/*********************************************************************************************************/

bool asal(int x){
    if(x==1) return false;
    for(int i=2;i*i<=x;++i)
        if(x%i==0)
            return false;
    return true;
}

int n;

int rev(int x){
    stringstream ss;
    string s;
    ss<<x;
    ss>>s;
    ss.clear();
    reverse(all(s));
    ss<<s;
    ss>>x;
    return x;
}

void solve(){
    cin>>n;
    if(asal(n)==false){
        cout<<"no\n";
        return;
    }
    if(asal(rev(n))==false){
        cout<<"no\n";
        return;
    }
    cout<<"yes\n";
    return;
}

int main(){
    test;
    fast;

    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}