#include<bits/stdc++.h>
using namespace std;

int cnt;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int mx=0;
        for(int i=0;i<n;++i){
            int a;
            cin>>a;
            mx=max(mx,a);
        }
        printf("Case %d: %d\n",++cnt,mx);
    }
}