#include<bits/stdc++.h>
using namespace std;
const unsigned long long N=2e5+5;
const unsigned long long MOD=998244353; 

unsigned long long ar[N];
unsigned long long n;
vector<unsigned long long> ust;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(unsigned long long i=1;i<=n;++i){
        unsigned long long a;
        cin>>a;
        ust.push_back( (i)*(n+1-i)%MOD*a%MOD);
    }
    for(unsigned long long i=0;i<n;++i)
        cin>>ar[i];
    sort(ust.begin(),ust.end());
    sort(ar,ar+n);
    reverse(ar,ar+n);

    unsigned long long sum=0;
    for(unsigned long long i=0;i<n;++i){
        sum=(sum+(ar[i]*ust[i]%MOD))%MOD;
    }
    cout<<sum;
}