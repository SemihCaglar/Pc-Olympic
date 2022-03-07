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

string a,b;
string virus;

int dp[105][105][105];

int f(int x,int y,int k){ // k: virusun kacincisina kadar gelmisiz? (dahil degil)
    int ans=-5;

    int &ref=dp[x][y][k];
    if(ref!=-1)
        return ref;

    if(k==virus.length())
        return -5;

    if(x==a.length() or y==b.length()){
        return 0;
    }

    int tmp;
    tmp=f(x+1,y,k);
    ans=max(ans,tmp);

    tmp=f(x,y+1,k);
    ans=max(ans,tmp);
    
    tmp=f(x+1,y+1,k);
    ans=max(ans,tmp);

    if(a[x]==b[y]){
        if(a[x]==virus[k]){
            int mn=INT_MAX;;
            if(a[x]==virus[0]){
                int maybe=1+f(x+1,y+1,1);
                mn=min(mn,maybe);
            }
            int maybe=1+f(x+1,y+1,k+1);
            mn=min(mn,maybe);
            ans=max(ans,mn);
        }
        else{
            int mn=INT_MAX;
            if(a[x]==virus[0]){
                int maybe=1+f(x+1,y+1,1);
                mn=min(mn,maybe);
            }
            int maybe=1+f(x+1,y+1,0);
            mn=min(mn,maybe);
            ans=max(ans,mn);
        }
    }
    return ref=ans;
}

int main(){
    fast;
    test();

    cin>>a>>b>>virus;

    for(int i=0;i<=a.length();++i)
        for(int j=0;j<=b.length();++j)
            for(int k=0;k<=virus.length();++k)
                dp[i][j][k]=-1;

    if(f(0,0,0)==0){
        cout<<0<<"\n";
        return 0;
    }
    // cout<<f(0,0,0)<<"\n";

    int x=0,y=0,k=0;

    while(true){
        int ans=0;


        if(x==a.length() or y==b.length() or k==virus.length()){
            break;
        }

        int tmp;
        tmp=f(x+1,y,k);
        ans=max(ans,tmp);

        tmp=f(x,y+1,k);
        ans=max(ans,tmp);
        
        tmp=f(x+1,y+1,k);
        ans=max(ans,tmp);

        if(a[x]==b[y]){
            if(a[x]==virus[k]){
                int mn=INT_MAX;;
                if(a[x]==virus[0]){
                    int maybe=1+f(x+1,y+1,1);
                    mn=min(mn,maybe);
                }
                int maybe=1+f(x+1,y+1,k+1);
                mn=min(mn,maybe);
                ans=max(ans,mn);
            }
            else{
                int mn=INT_MAX;
                if(a[x]==virus[0]){
                    int maybe=1+f(x+1,y+1,1);
                    mn=min(mn,maybe);
                }
                int maybe=1+f(x+1,y+1,0);
                mn=min(mn,maybe);
                ans=max(ans,mn);
            }
        }
        
        tmp=f(x+1,y,k);
        if(tmp==ans){
            x++;
            continue;
        }        

        tmp=f(x,y+1,k);
        if(tmp==ans){
            y++;
            continue;
        }

        tmp=f(x+1,y+1,k);
        if(tmp==ans){
            x++,y++;
            continue;
        }

        if(a[x]==b[y]){
            if(a[x]==virus[k]){
                int mn=INT_MAX;;
                if(a[x]==virus[0]){
                    int maybe=1+f(x+1,y+1,1);
                    if(maybe==ans){
                        cout<<a[x];
                        x++,y++,k=1;
                        continue;
                    }
                }
                int maybe=1+f(x+1,y+1,k+1);
                if(maybe==ans){
                    cout<<a[x];
                    x++,y++,k++;
                    continue;
                }
            }
            else{
                int mn=INT_MAX;
                if(a[x]==virus[0]){
                    int maybe=1+f(x+1,y+1,1);
                    if(maybe==ans){
                        cout<<a[x];
                        x++,y++,k=1;
                        continue;
                    }
                }
                int maybe=1+f(x+1,y+1,0);
                if(maybe==ans){
                    cout<<a[x];
                    x++,y++,k=0;
                    continue;
                }
            }
        }
    }


    return 0;
}