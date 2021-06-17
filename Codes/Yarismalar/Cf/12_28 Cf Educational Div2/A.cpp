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

void filereopen(){
    freopen("/home/semihcaglar/Desktop/Pc Olympic/test/test.in","r",stdin);
    freopen("/home/semihcaglar/Desktop/Pc Olympic/test/test.out","w",stdout);
    freopen("/home/semihcaglar/Desktop/Pc Olympic/test/test.err","w",stderr);
}

#define test filereopen()

void solve();

int main(){
    //test;
    fast;
    solve();
    return 0;
}

int t;
string s;

void solve(){
	cin>>t;
	while(t--){
		bool flag=true;
		cin>>s;
		if(s.length()%2==1){
			cout<<"NO\n";
			continue;
		}
		for(int i=0;i<s.length();++i){
			if(s[i]=='(' and i==s.length()-1 ){
				cout<<"NO\n";
				flag=false;
				break;
			}
			else if(s[i]==')' and i==0 ){
				cout<<"NO\n";
				flag=false;
				break;
			}
		}
		if(flag)
		cout<<"YES\n";
	}
}