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

int n,m;
char a[30][30];
int mx=-1;

int main(){
    fast;
    // test();

    cin>>n>>m;    
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>a[i][j];
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;++j){
            for(int k=1;k<=m;++k)
                for(int p=k;p<=m;++p){
                    bool flag=true;

                    for(int tmp1=i;tmp1<=j;++tmp1)
                        for(int tmp2=k;tmp2<=p;++tmp2)
                            if(a[tmp1][tmp2]=='1')
                                flag=false;

                    if(flag){
                        mx=max(mx, 2*(p-k+j-i+2) );
                    }
                }
        }
    cout<<mx<<"\n"; 

    return 0;
}