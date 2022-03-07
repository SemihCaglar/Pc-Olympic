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

int t;
int n;

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>n;
        stringstream ss;
        double tmp=pow(n,1.0/3.0);
        ss<<tmp;
        string s;
        ss>>s;
        int cnt=-1;
        for(auto i: s){
            cout<<i;
            if(i=='.')
                cnt=0;
            if(cnt!=-1)
                cnt++;
            if(cnt==5)
                break;
        }

        if(cnt==-1){
            cout<<".";   
            cnt++;
        }
        for(int i=0;i<4-cnt;++i)
            cout<<"0";
        cout<<"\n";
    }    

    return 0;
}