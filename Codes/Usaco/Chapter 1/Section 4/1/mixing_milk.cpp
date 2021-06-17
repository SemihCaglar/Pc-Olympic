/*
ID: semihca1
TASK: milk
LANG: C++                 
*/
#define isim  "milk"

// Radix sort kullanılarak da yapılabilir, O(N) zaman alır. Ama benimki O(nlogn)
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int n,m;
priority_queue<ii> milk;

int main() {
    freopen( &*(string(isim)+".in").begin() , "r" , stdin );
    freopen( &*(string(isim)+".out").begin() , "w" , stdout );
    
    cin>>n>>m;
    int cnt=0;
    for(int i=0;i<m;++i){
        int p,a;
        cin>>p>>a;
        milk.push(ii(-p,a));
    }
    while(n){
        ii tmp=milk.top();
        milk.pop();
        int ucret=tmp.first*-1;
        int adet=tmp.second;

        if(adet<=n){
            cnt+=ucret*adet;
            n-=adet;
        }
        else{
            cnt+=n*ucret;
            n-=n;
        }
    }
    cout<<cnt<<"\n";
}    