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
int n,k;
int he[(int)2e5+5];

void solve(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0;i<n;++i)
			he[i]=-1;

		priority_queue<ii> pq; // (-taban,indeks)
		for(int i=0;i<n;++i){
			int a;
			cin>>a;
			if(i==0 or i==n-1)
				he[i]=a;
			else
				pq.push(ii(-a,i));
		}
		while(!pq.empty()){
			ii tmp=pq.top();
			pq.pop();
			int h=tmp.fi*-1,ind=tmp.se;
			//dbg(ind),dbg(h);
			int enfazla=h+k-1;

			int enaz=0;
			if(ind>0 and he[ind-1]!=-1){
				int sol=he[ind-1];
				enaz=max(enaz,sol+1-k);
				enfazla=min(enfazla,sol-1+k);
			}
			if(ind<n-1 and he[ind+1]!=-1){
				int sag=he[ind+1];
				enaz=max(enaz,sag+1-k);
				enfazla=min(enfazla,sag-1+k);
			}
			dbg(enaz),dbg(enfazla),cerr<<endl;
			if(enaz>enfazla){
				cout<<"NO\n";
				goto son;
			}
			else
				he[ind]=enfazla;
		}
		cout<<"YES\n";
		son:
			5;
	}
}