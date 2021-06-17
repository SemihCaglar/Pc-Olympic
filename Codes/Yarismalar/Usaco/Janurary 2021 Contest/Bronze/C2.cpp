#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define test freopen("/home/semih/Desktop/Pc Olympic/test/test.in","r",stdin);freopen("/home/semih/Desktop/Pc Olympic/test/test.out","w",stdout)
typedef long long ll;

int n;
int a[25],b[25];

int kactane(int ind){
    int cnt=0;
    for(int i=ind;i<n and a[i]<=b[ind];++i,cnt++);
    return cnt;
}

int main(){
    fast;
    //test;
    
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<n;++i)
        cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);

    ll ans=1;
    for(int i=0;i<n;++i){
        ans*=kactane(i);
        // cerr<<(kactane(i))<<endl;
    }
    cout<<ans;
}