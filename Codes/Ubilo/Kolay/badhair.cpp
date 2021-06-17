#define isim  "badhair"

#include<bits/stdc++.h>
using namespace std;
long long n,result;
stack<int> cow;

int main() {
    freopen( &*(string(isim)+".gir").begin() , "r" , stdin );
    freopen( &*(string(isim)+".cik").begin() , "w" , stdout );
    cin>>n;
    for(int i=1;i<=n;++i){
        int x;
        cin>>x;
        while(!cow.empty()&&cow.top()<=x)
            cow.pop();
        result+=cow.size();
        cow.push(x);
    }
    cout<<result;
}    