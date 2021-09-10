#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int MOD=998244353;
int n;
long long fibo[N];

long long hizlius(int a,long long int b){
    if(b==0)
        return 1;
    if(b==1)
        return a;
    long long c=hizlius(a,b/2);
    
    if(b%2==0)
        return c*c%MOD;
    else
        return c*c%MOD*a%MOD;  
}

int main(){
    cin>>n;
    fibo[0]=fibo[1]=fibo[2]=1;
    for(int i=3;i<=n;++i){
        fibo[i]=(fibo[i-1]%MOD+fibo[i-2]%MOD)%MOD;
    }
    long long neblm=fibo[n];
    long long carpan=hizlius( hizlius(2,n),(MOD-2));
    long long sonuc=(1LL*neblm*carpan)%MOD;
    cout<<sonuc;
}
// çıkıyom o zaman
