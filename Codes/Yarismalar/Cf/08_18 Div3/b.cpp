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

void test(string name="/home/semih/Desktop/Pc Olympic/test/test"){
    freopen(&*(name+".in").begin(),"r",stdin);
    freopen(&*(name+".out").begin(),"w",stdout);
}
/*****************************************************************************************/

int t,a,b,c;

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        int n=abs(a-b)*2;
        dbg(n);
        int oluru=(c+n/2);
        dbg(oluru);
        if(max(max(a,b),c)>n)
            cout<<-1<<"\n";
        else if(oluru==n)
            cout<<n<<"\n";
        else
            cout<<(c+n/2)%n<<"\n";
    }    

    return 0;
}