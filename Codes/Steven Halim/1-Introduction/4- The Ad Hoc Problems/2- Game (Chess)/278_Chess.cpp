#include<bits/stdc++.h>
using namespace std;

int t;
int n,m;
char c;

int main(){
    cin>>t;
    while(t--){
        cin>>c>>n>>m;
        int ans;
        switch(c){
            case 'r': ans=min(n,m); break;
            case 'k': ans=((n+1)/2)*((m+1)/2) + (n/2)*(m/2); break;
            case 'Q': ans=min(n,m); break;
            case 'K': ans=((n+1)/2)*((m+1)/2); break;
        }
        cout<<ans<<'\n';
    }
}