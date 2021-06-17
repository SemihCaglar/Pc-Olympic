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
    test;
    fast;
    solve();
    return 0;
}
int t;

void solve(){
	cin>>t;
	while(t--){
		int n,m;
		cin>>n;
		int mx1=0;
		int sum=0;
		for(int i=0;i<n;++i){
			int a;
			cin>>a;
			sum+=a;
			mx1=max(mx1,sum);
		}
		cin>>m;
		int mx2=0;
		sum=0;
		for(int i=0;i<m;++i){
			int a;
			cin>>a;
			sum+=a;
			mx2=max(mx2,sum);
		}
		cout<<mx1+mx2<<'\n';
		
	}
}