#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ulli;
const int N=1e9+5;
vector<ulli> v;

int main(){
    v.push_back(0);
    v.push_back(2);
    int h=1;
    while(++h){
        int a=v[h-1]+(3*h-1);
        if(a>N)
            break;
        v.push_back(a);
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int cnt=0;
        while(n>1){
            auto oluru=upper_bound(v.begin(),v.end(),n);
            oluru--;
            n-=*oluru;
            ++cnt;
        }
        cout<<cnt<<'\n';
    }
        
}