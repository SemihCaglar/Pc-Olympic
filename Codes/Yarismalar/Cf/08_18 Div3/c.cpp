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

int t,n;

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>n;
        int kok=sqrt(n);
        if(kok*kok<n)
            kok++;
        int sag=kok*kok-kok+1;
        if(n<=kok*kok and n>=sag)
            cout<<kok<<" "<<kok*kok-n+1<<"\n";
        else
            cout<<n-(sag-kok)<<" "<<kok<<"\n";
    }    

    return 0;
}