#include<bits/stdc++.h>
using namespace std;
 
const int MOD=1e9+7;
int n;
 
int fastpow(int a){
    if(a==0)
        return 1;
    int b=fastpow(a/2);
    b=1LL*b*b%MOD;
    if(a%2)
        b=1LL*b*2%MOD;
    return b;
}
 
int main(){
	cin>>n;
    cout<<fastpow(n)<<"\n";
}