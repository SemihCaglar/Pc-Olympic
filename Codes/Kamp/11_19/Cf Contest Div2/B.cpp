#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int t,n;
int a[N];
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;++i)
            cin>>a[i];
        if(n==2){
            cout<<"0\n";
            continue;
        }
        ll sum=0LL;
        int mx=-1;
        for(int i=0;i<n;++i){
            sum+=a[i];
            mx=mx==-1?a[i]:max(mx,a[i]);
        }
        ll tmp=sum;
        mx=max(1LL*mx*(n-1),tmp);
        long long result=1LL*ceil(1.0*(ll)mx/(n-1))*(n-1);
        cout<<result-sum<<'\n';
    }
}