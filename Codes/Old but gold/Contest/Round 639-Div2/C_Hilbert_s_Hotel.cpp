#include<bits/stdc++.h>
using namespace std;

int modd(int k,int n){
    int mod=k%n;
    if(mod<0) mod+=n;
    return mod;
}

bool shuffle(int n,int guest[],int room[]){
    
    bool vis[n+5];
    for(int i=0;i<n;++i)
        vis[i]=false;
    for(int i=0;i<n;++i){  // konukları iterative.
        
    }
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ar[n+5];
        for(int i=0;i<n;++i)
            cin>>ar[i];
        int guests[n+5];
        for(int i=0;i<n;++i)
            guests[i]=i;
        

    }
}