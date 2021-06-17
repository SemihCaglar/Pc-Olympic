#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
const int N=2e5+5;

int t;
ll n;

int asal[N];

int find(ll n){
    ll buyukn=n;
    for(ll i=2;1LL*i*i<=buyukn;++i){
        while(n%i==0){
            asal[i]++;
            n/=i;
        }
    }
    int mx=-1,retu=-1;
    for(int i=2;1LL*i*i<=buyukn;++i){
        if(asal[i]>mx and asal[i]>0){
            mx=asal[i];
            retu=i;
        }
    }
    return retu;
}

int main(){
    cin>>t;
    while(t--){
        cin>>n;
        ll buyukn=n;
        int mxasal=find(n);
        if(mxasal==-1){
            cout<<"1\n"<<n<<'\n';
            continue;
        }
        cout<<asal[mxasal]<<'\n';
        for(ll i=1;i<asal[mxasal];++i){
            cout<<mxasal<<' ';
            n/=mxasal;
        }
        cout<<n<<'\n';
        for(ll i=2;1LL*i*i<=buyukn;++i)
            asal[i]=0;

    }
}