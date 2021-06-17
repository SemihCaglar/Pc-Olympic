#define isim  "ucgen2"

#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen( &*(string(isim)+".gir").begin() , "r" , stdin );
    freopen( &*(string(isim)+".cik").begin() , "w" , stdout );
    int n;
    cin>>n;
    cout<<"*\n**\n";
    for(int i=3;i<n;++i){
        cout<<'*';
        for(int j=0;j<i-2;++j)
            cout<<' ';
        cout<< "*\n" ;
    }
    if(n>2)
        for(int i=0;i<n;++i)
            cout<<'*';
}    