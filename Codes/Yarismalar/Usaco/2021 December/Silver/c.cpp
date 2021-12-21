#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
#define fi first
#define se second
#define dbg(x) cerr<<#x<<": "<<x<<endl
#define test freopen("/home/semih/Desktop/Pc Olympic/test/test.in","r",stdin); freopen("/home/semih/Desktop/Pc Olympic/test/test.out","w",stdout)

const int N=5e3+5;
int n,m;
ll sum;
int bas[2*N],son[2*N];

int main(){
    // test;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i=0;i<n;++i){
        int x,y;
        cin>>x>>y;
        bas[x]++,son[y]++;
    }

    for(int i=0;i<=2*m;++i){
        ll cnt=0;
        for(int j=0;j<=i;++j)
            cnt+= 1LL*bas[j]*bas[i-j];
        sum+=cnt;
        cnt=0;
        for(int j=0;j<=i-1;++j)
            cnt+= 1LL*son[j]*son[i-1-j];
        sum-=cnt;
        cout<<sum<<"\n";
    }
}