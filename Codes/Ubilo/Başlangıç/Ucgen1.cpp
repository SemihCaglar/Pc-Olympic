#define isim  "ucgen1"

#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen( &*(string(isim)+".gir").begin() , "r" , stdin );
    freopen( &*(string(isim)+".cik").begin() , "w" , stdout );
    int n;
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=0;j<i;++j)
            cout<<'*';
        cout<<'\n';
    }
}    