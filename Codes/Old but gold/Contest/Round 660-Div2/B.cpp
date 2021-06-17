#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sekiz=ceil(n/4.0);
        int dokuz=n-sekiz;
        for(int i=0;i<dokuz;++i)
            cout<<'9';
        for(int i=0;i<sekiz;++i)
            cout<<'8';
        cout<<'\n';
    }
}