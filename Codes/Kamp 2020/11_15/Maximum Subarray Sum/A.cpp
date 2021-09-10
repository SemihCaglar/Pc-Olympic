#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int n;

int main(){
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    long long maxx=LONG_LONG_MIN,top=0;
    bool durum=false;
    for(int i=0;i<n;++i){
        top=max(0LL+a[i],top+a[i]);
        maxx=max(maxx,top);
        if(a[i]>=0)
            durum=true;
    }
    if(durum==false){
        maxx=LONG_LONG_MIN;
        for(int i=0;i<n;++i){
            maxx=max(maxx,0LL+a[i]);
        }
        cout<<maxx;
    }
    else
        cout<<maxx;
}