#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        if(n>=3&&m>=2||m>=3&&n>=2){
            cout<<"NO\n";
        }
        else
            cout<<"YES\n";

    }
}