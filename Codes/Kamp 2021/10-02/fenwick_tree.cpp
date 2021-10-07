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

const int N=2e5+5;
int n,q;
int a[N];
ll fen[N];


ll query(int x){ // x. indekse kadar olan toplam
    ll sum=0;
    while(x>0){
        sum+=fen[x];
        x -= x&-x;
    }
    return sum;
}

void update(int x,int k){ // x indeksini k artır
    while(x<=n){
        fen[x]+=k;
        x += x&-x;
    }
}

int main(){
    fast;
    test();
    ifstream fin("test_output.txt");
    cin>>n>>q;    
    for(int i=1;i<=n;++i){
        cin>>a[i];
        update(i,a[i]);
    }
    while(q--){
        int t,x,y;
        cin>>t>>x>>y;
        if(t==1)
            update(x,y-a[x]);
        else{
            ll cevap=query(y)-query(x-1);
            cout<<cevap<<"\n";
            ll tmp;
            fin>>tmp;
            if(tmp!=cevap){
                dbg(cevap);
                dbg(tmp);
                dbg(x),dbg(y);
                dbg(q);
                // return 0;
            }
            
        }
    }

    return 0;
}