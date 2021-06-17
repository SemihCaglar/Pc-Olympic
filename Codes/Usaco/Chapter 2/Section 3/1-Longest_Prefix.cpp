/*
ID: semihca1
TASK: prefix
LANG: C++  
*/
#define fname  "prefix"

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
    if(name=="/mnt/c/Users/semihcaglar/Desktop/Pc Olympic/test")
        freopen(&*(string(name)+".err").begin(),"w",stderr);
    else if(name=="test")
        name="/mnt/c/Users/semihcaglar/Desktop/Pc Olympic/test";
    freopen(&*(string(name)+".in").begin(),"r",stdin);
    freopen(&*(string(name)+".out").begin(),"w",stdout);
}

#ifndef fname
    #define fname "/mnt/c/Users/semihcaglar/Desktop/Pc Olympic/test"
#endif
#define test filereopen(string(fname))

/***********************************/

const int N=2e5+5;

vector<string> pri;
string s;
bool dp[N];

void solve(){
    while(cin>>s,s!=".")
        pri.pb(s);
    
    string tmp;
    s="";
    while(cin>>tmp)
        s+=tmp;

    int mx=-1;
    
    forr(i,0,s.length()){
        for(string j:pri){
            int len=j.length();
            if(i-len==-1)
                goto theschool;
            if(i-len<0 or dp[i-len]==false)
                continue;
            
            theschool:
            string tmp=s.substr(i-len+1,len);
            if(tmp==j){
                dp[i]=true;
                break;
            }
        }
        if(dp[i])
            mx=i;
    }
    cout<<mx+1<<'\n';
}

int main(){
    test;
    fast;

    int t=1;
    // cin>>t;
    while(t--)
        solve();
    return 0;
}