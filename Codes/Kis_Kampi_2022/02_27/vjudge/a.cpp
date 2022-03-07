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
#define all(v) v.begin(),v.end()
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define cdbg(v,n) for(int i=0;i<n;++i) cerr<<#v<<"["<<i<<"]:"<<v[i]<<endl
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void test(string name="/home/semih/Desktop/Pc Olympic/test/test"){
    freopen(&*(name+".in").begin(),"r",stdin);
    freopen(&*(name+".out").begin(),"w",stdout);
}
/*****************************************************************************************/

int n;
string a,b;


int main(){
    fast;
    // test();

    while(cin>>n>>a>>b){
        vi pi(a.length()+b.length()+10);
        pi[0]=0;
        a+="#"+b;

        for(int i=1;i<a.length();++i){
            int j=pi[i-1];
            while(j!=0 && a[i]!=a[j])
                j=pi[j-1];
            if(a[i]==a[j])
                j++;
            pi[i]=j;

            if(pi[i]==n)
                cout<<i-2*n<<"\n";
        }        
        cout<<"\n";
    }    

    return 0;
}