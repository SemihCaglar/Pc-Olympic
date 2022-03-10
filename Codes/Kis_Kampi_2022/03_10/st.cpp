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

const int N=2e5+5;
int n,q;
int ar[N],tree[4*N];

int build(int k, int l, int r){
    if(l==r)
        return tree[k]=ar[l];
    int m=(l+r)/2;
    return tree[k] = min( build(2*k,l,m) , build(2*k+1,m+1,r) );
}

int query(int k, int l, int r, int x, int y){
    if(x<=l and y>=r)
        return tree[k];
    if(x>r or y<l)
        return INT_MAX;
    if(l==r)
        return tree[k];
    int m=(l+r)/2;
    return min( query(2*k,l,m,x,y) , query(2*k+1,m+1,r,x,y) );
}

int update(int k, int l, int r, int x, int y){
    if(x>r or x<l)
        return tree[k];
    if(l==r)
        return tree[k]=y;
    int m=(l+r)/2;
    return tree[k] = min( update(2*k,l,m,x,y) , update(2*k+1,m+1,r,x,y) );
}

int main(){
    fast;
    // test();

    cin>>n>>q;
    for(int i=1;i<=n;++i)
        cin>>ar[i];

    build(1,1,n);    
    while(q--){
        int op, x,y;
        cin>>op>>x>>y;
        if(op==2)
            cout<<query(1,1,n,x,y)<<"\n";
        else
            update(1,1,n,x,y);  
    }

    return 0;
}