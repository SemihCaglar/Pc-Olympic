#include<bits/stdc++.h>
using namespace std;

int ar[105];

int main(){
    freopen("dizi4.gir","r",stdin);
    freopen("dizi4.cik","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        ar[a]++;
    }
    int mx=0,res;
    for(int i=100;i>=0;--i){
        if(ar[i]>=mx){
            mx=ar[i];
            res=i;
        }
    }
    cout<<res;
}