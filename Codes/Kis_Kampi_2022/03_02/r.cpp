#include<bits/stdc++.h>
using namespace std;
#define int long long

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

int n,q;
vi tmp1, tmp2;
vi ar;
typedef pair<int,ii> i3;
vector<i3> sorgu;

int query(int l, int r){
    if(l==0)
        return ar[r];
    return ar[r]-ar[l-1];
}

int32_t main(){
    fast;
    // test();

    cin>>n;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        tmp1.pb(x);
    }
    cin>>q;
    for(int i=0;i<q;++i){
        int op;
        cin>>op;
        if(op==1){
            int l,r;
            cin>>l>>r;
            l--,r--;
            sorgu.pb({tmp2.size(),{l,r}});
        }
        else{
            int x;
            cin>>x;
            tmp2.pb(x);
        }
    }
    reverse(all(tmp2));
    for(auto i: tmp2)
        ar.pb(i);
    for(auto i: tmp1)
        ar.pb(i);
    
    for(int i=1;i<ar.size();++i)
        ar[i]+=ar[i-1];
    
    for(i3 i: sorgu){
        int neblm=tmp2.size()-i.fi;
        cout<<query(neblm+i.se.fi,neblm+i.se.se)<<"\n";
    }


    return 0;
}