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

void test(string name="/home/ecr/Desktop/pc-olympic/test/test"){
    freopen(&*(name+".in").begin(),"r",stdin);
    freopen(&*(name+".out").begin(),"w",stdout);
}
/*****************************************************************************************/
#define int long long

const int N=2e5+5;
int ar[N],T[N];
int n,q;

void update(int x, int k){
    for(;x<=n;x+=x&-x)
        T[x]+=k;
}

int getsum(int x){
    int sum=0;
    for(;x>0;x-=x&-x)
        sum+=T[x];
    return sum;
}

int query(int x, int y){
    if(x==0)
        return getsum(y);
    return getsum(y)-getsum(x-1);
}

int32_t main(){
    fast;
    // test();

    cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>ar[i];
        update(i,ar[i]);
    }    
    while(q--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            update(b,c-ar[b]);
            ar[b]=c;
        }
        else{
            cout<<query(b,c)<<"\n";
        }
    }

    return 0;
}