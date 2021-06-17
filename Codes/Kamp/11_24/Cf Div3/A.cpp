#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%2==0){
        for(int i=n;i>0;--i)
            cout<<i<<' ';
        }
        else{
            for(int i=n;i>n/2+2;--i)
                cout<<i<<' ';
            cout<<n/2+1<<' '<<n/2+2<<' ';
            for(int i=n/2;i>0;i--)
                cout<<i<<' ';
        }
        cout<<'\n';
    }
}