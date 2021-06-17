/*
ID: semihca1
TASK: frac1
LANG: C++                 
*/
#define isim  "frac1"

#include<bits/stdc++.h>
using namespace std;
int n;
typedef pair<int,int> ii;
typedef pair<long double,ii> fraction;
priority_queue<fraction,vector<fraction>,greater<fraction>> a;

int main() {
    // freopen( &*(string(isim)+".in").begin() , "r" , stdin );
    // freopen( &*(string(isim)+".out").begin() , "w" , stdout );
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<i;++j){
            if(__gcd(i,j)==1)
                a.push(fraction(j*1.0/i,ii(j,i)));
        }
    }
    a.push(fraction(0.0,ii(0,1)));
    a.push(fraction(1.0,ii(1,1)));
    while(!a.empty()){
        fraction i=a.top();
        a.pop();
        cout<<i.second.first<<'/'<<i.second.second<<endl;
    }

    
}    