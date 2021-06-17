#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c0,c1,h;
        cin>>n>>c0>>c1>>h;
        string s;
        cin>>s;
        int ar[]={0,0};
        for(auto i:s)
            ar[i-'0']++;
        if(h+c1<c0)
            c0=h+c1;
        if(h+c0<c1)
            c1=h+c0;
        cout<<c1*ar[1]+c0*ar[0]<<'\n';
    }
}