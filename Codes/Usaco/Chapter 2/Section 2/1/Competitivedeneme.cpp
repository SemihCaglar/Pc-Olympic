/*
ID: semihca1
TASK: preface
LANG: C++  
*/
#define fname  "preface"

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define _pb push_back
#define _mp make_pair
#define _fi first
#define _se second
#define _sp " "
#define all(v) v.begin(),v.end()
#define forr(i,a,b) for(int i=a;i<b;++i)
#define cfor(i,v) for(auto i=v.begin();i!=v.end();++i)
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

#ifndef fname
#define fname "test"
#endif
#define test freopen( &*(string(fname)+".in").begin() , "r" , stdin );\
freopen( &*(string(fname)+".out").begin() , "w" , stdout )

int N=1e5+5;
const int INF=INT_MAX;

int n,t=1;
map<int,char> mp={ {1,'I'},{5,'V'},{10,'X'},{50,'L'},{100,'C'},{500,'D'},{1000,'M'},{5000,'S'} };
map<int,int> help={ {1,1},{5,1},{10,1},{50,10},{100,10},{500,100},{1000,100},{5000,1000} };
map<char,int> ans;

void f(int n){
    while(n){
        pair<int,char> onceki;
        for(auto i:mp){
            if(i.first>n){
                auto prev=make_pair(help[i.first],mp[help[i.first]]);
                if(i.first-prev.first<=n){
                    n-=i.first-prev.first;
                    ans[i.second]++;
                    ans[prev.second]++;
                }
                else{
                    int div=n/onceki.first;
                    n-=div*onceki.first;
                    ans[onceki.second]+=div;
                }
                break;
            }
            else if(i.first==n){
                ans[i.second]++;
                n-=i.first;
                break;
            }
            onceki=i;
        }
    }
}

void solve(){
    cin>>N;
    for(int i=1;i<=N;++i)
        f(i);
    
    for(auto i:mp){
        if(ans.count(i.second)==0)
            break;
        cout<<i.second<<' '<<ans[i.second]<<'\n';
    }
}

int main(){
    // test;
    fast;

    // cin>>t;
    while(t--)
        solve();
    return 0;
}