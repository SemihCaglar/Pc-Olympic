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

const int N=2e5+5;
int t,n,h[N];

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>n;
        set<int> st;
        forr(i,0,n)
            cin>>h[i];
        sort(h,h+n);

        int mn=INT_MAX;
        ii pr;
        for(int i=0;i+1<n;++i){
            if(h[i+1]-h[i]<mn){
                mn=h[i+1]-h[i];
                pr={h[i+1],h[i]};
                st.clear();
                st.insert(i+1);
                st.insert(i);
            }
        }
        vi ans(n);
        ans[0]=pr.se;
        ans[n-1]=pr.fi;

        if(n>3){
            for(int i=0;i<n;++i)
                if(h[i]>ans[0] and st.count(i)==0){
                    st.insert(i);
                    ans[1]=h[i];
                    break;
                }
            int ind;
            for(ind=0;ind<n and h[ind]<ans[n-1];++ind);
            st.insert(ind);
            ans[n-2]=h[ind];
        }
        int ind=2;
        for(int i=0;i<n;++i){
            if(st.count(i)==0)
                ans[ind++]=h[i];
        }
        forr(i,0,n)
            cout<<ans[i]<<sp;
        cout<<"\n";
        
        
    }

    return 0;
}