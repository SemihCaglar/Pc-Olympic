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

const int N=1e5+5;
int n,m,k;
int ar[N];
int lazy[N]; // updatelerin toplamini bul. 
int lazy2[N];

typedef pair<ii,int> iii;
iii updateler[N];

int32_t main(){
    fast;
    // test();

    cin>>n>>m>>k;    
    for(int i=0;i<n;++i)
        cin>>ar[i];
    for(int i=0;i<m;++i){
        int l,r,d;
        cin>>l>>r>>d;
        l--,r--;
        updateler[i]={{l,r},d};
    }
    for(int i=0;i<k;++i){
        int x,y;
        cin>>x>>y;
        x--,y--;
        lazy[x]++;
        if(y+1<m)
            lazy[y+1]--;
    }
    for(int i=1;i<m;++i)
        lazy[i]+=lazy[i-1];
    
    for(int i=0;i<m;++i){
        int bas,son,c;
        bas=updateler[i].fi.fi,son=updateler[i].fi.se,c=updateler[i].se;
        lazy2[bas]+=lazy[i]*c;
        if(son+1<n)
            lazy2[son+1]-=lazy[i]*c;
    }
    for(int i=1;i<n;++i)
        lazy2[i]+=lazy2[i-1];
    
    for(int i=0;i<n;++i)
        cout<<ar[i]+lazy2[i]<<" ";
    cout<<"\n";
    

    return 0;
}