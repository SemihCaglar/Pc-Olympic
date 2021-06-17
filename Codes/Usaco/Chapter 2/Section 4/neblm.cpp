/*
ID: semihca1
TASK: fracdec
LANG: C++  
*/
//#define fname  "fracdec"

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
    test;
    fast;
    solve();
    return 0;
}
/*****************************************************************************************/

int n,d;
map<string,vi> mp; // İki ardışık rakamın ilk geçtiği indeksleri tutuyor.

string fractionsToDecimals(int n,int d){
    string ans="";
    while(n){
        n*=10;
        char ctmp='0'+n/d;
        ans+=ctmp;
        n%=d;
        if(ans.size()<2)
            continue;
        string tmp="";
        int len=ans.length();
        tmp+=ans[len-2];
        tmp+=ans[len-1];
        mp[tmp].pb(len-2);
        
        if(mp[tmp].size()>=log10(d)+1 and ctmp!='0'){
            int log=log10(d)+1;
            int it=mp[tmp].size()-1;
            int fark=mp[tmp][it]-mp[tmp][it-1];
            bool flag=true;
            for(int i=0;i<log;++i){
                int tmpFark=mp[tmp][it-i]-mp[tmp][it-i-1];
                if(tmpFark!=fark)
                    flag=false;
            }
            if(flag){
                int index = mp[tmp][1];
                ans.resize(index);
                int bas=mp[tmp][0];
                ans.insert(bas, "(");
                ans += ')';
                return ans;
            }
        }
    }
    return ans;

}

void solve(){
    cin>>n>>d;
    string ans="";
    ans+=to_string(n/d);
    ans+=".";
    string bolum=fractionsToDecimals(n%d,d);
    if(bolum=="")
        ans+="0";
    else
        ans+=bolum;
    for(int i=0;i<ans.length();++i){
        cout<<ans[i];
        if((i+1)%76==0)
            cout<<'\n';
    }
    if(ans.length()%76)
        cout<<'\n';
}