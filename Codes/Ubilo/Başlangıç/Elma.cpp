#define isim  "jabuka"

#include<bits/stdc++.h>
using namespace std;

int r,g;

int main() {
    freopen( &*(string(isim)+".gir").begin() , "r" , stdin );
    freopen( &*(string(isim)+".cik").begin() , "w" , stdout );
    cin>>r>>g;
    int ebob= __gcd(r,g);
    for(int i=1;i<=ebob;++i){
        if(ebob%i==0){
            cout<<i<<' '<<r/i<<' '<<g/i<<'\n';
        }
    }
}  