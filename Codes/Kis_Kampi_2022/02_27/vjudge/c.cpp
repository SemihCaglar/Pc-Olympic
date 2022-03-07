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

int t,n;
string a,b;

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>a>>b;
        swap(a,b);
        dbg(a);
        n=a.length();
        vi pi(a.length()+b.length()+10);
        pi[0]=0;
        a+="#"+b;

        vi ans;

        for(int i=1;i<a.length();++i){
            int j=pi[i-1];
            while(j!=0 && a[i]!=a[j])
                j=pi[j-1];
            if(a[i]==a[j])
                j++;
            pi[i]=j;

            if(pi[i]==n)
                ans.pb(i-2*n+1);
        }  

        if(ans.empty())
            cout<<"Not Found\n";
        else{
            cout<<ans.size()<<"\n";
            for(auto i: ans)
                cout<<i<<" ";
            cout<<"\n";
        }      
        cout<<"\n";
    }    

    return 0;
}