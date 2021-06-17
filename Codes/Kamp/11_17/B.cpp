#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[200005];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin>>n>>k;
        for(int i=0;i<n*k;++i)
            cin>>a[i];
        int bas=0,son=n*k-1;
        int medy=(ceil(n/2.0));
        long long top=0;
        while(bas<=son){
            for(int i=1;i<medy;++i)
                bas++;
            for(int i=n;i>medy;--i)
                son--;
            top+=a[son];
            son--;
        } 
        cout<<top<<endl;
    }

}