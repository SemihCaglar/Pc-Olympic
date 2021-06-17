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

void filereopen(string name){
    if(name=="/home/semihcaglar/Desktop/Pc Olympic/test/test")
        freopen(&*(name+".err").begin(),"w",stderr);
    else if(name=="test")
        name="/home/semihcaglar/Desktop/Pc Olympic/test/test";
    freopen(&*(name+".in").begin(),"r",stdin);
    freopen(&*(name+".out").begin(),"w",stdout);
}

#ifndef fname
    #define fname "/home/semihcaglar/Desktop/Pc Olympic/test/test"
#endif
#define test filereopen(fname)

void solve();

int main(){
    // test;
    fast;
    solve();
    return 0;
}
/*****************************************************************************************/

map<int,int> sayilar ={ {0,119},{1,18},{2,93},{3,91},
{4,58},{5,107},{6,111},{7,82},{8,127},{9,123} };

int N,K;
int binary[2005];
short kacoldu[2005];
short cevap[2005];

bool valid(short ar[]){
    for(int i=0;i<N;++i)
        if(ar[i]==-1)
            return false;
    return true;
}

int need(int x,int y){
    int sum=0;
    for(int i=0;i<7;++i){
        bool a=x&(1<<i),b=y&(1<<i);
        if(a==1 and b==0)
            return -1;
        if(a==0 and b==1)
            sum++;
    }
    return sum;
}

short dp[2005][2005];
short retval[2005][2005];

void check(){
    if(valid(kacoldu)==false)
        return;
    for(int i=0;i<N;++i){
        if(cevap[i]==-1 or kacoldu[i]>cevap[i])
            for(;i<N;++i)
                cevap[i]=kacoldu[i];
        else if(cevap[i]>kacoldu[i])
            for(;i<N;++i)
                cevap[i]=cevap[i];
    }
}


bool f(int n,int k){
    if(n==N){
        if(k==0){
            // check();
            return retval[n][k]=true;
        }
        return retval[n][k]=false;
    }
    bool flag=false;
    if(retval[n][k]!=-1)
        return retval[n][k];
    for(int i=0;i<10;++i){
        int a=need(binary[n],sayilar[i]);
        if(a==-1)
            continue;
        kacoldu[n]=i;
        if(k>=a){
            if( i>=cevap[n] and f(n+1,k-a) ){
                flag=true;
                cevap[n]=i;
                dp[n][k]=i;
            }
        }
    }
    return retval[n][k]=flag;
}


void solve(){
    
    cin>>N>>K;
    forr(i,0,N){
        int a=0;
        forr(j,0,7){
            char x;
            cin>>x;
            a|=(x-'0')<<(6-j);
        }
        binary[i]=a;
    }
    memset(cevap,-1,sizeof(cevap));
    forr(i,0,N+1){
        forr(j,0,K+1){
            dp[i][j]=-1;
            retval[i][j]=-1;
        }
    }
    f(0,K);
    if(valid(cevap)==false){
        cout<<-1;
        return;
    }
    forr(i,0,N){
        cout<<dp[i][K];
        K-=need(binary[i],sayilar[dp[i][K]]);
    }
}