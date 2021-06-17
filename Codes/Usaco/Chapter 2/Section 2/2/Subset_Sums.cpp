/*
ID: semihca1
TASK: subset
LANG: C++                 
*/
#define isim  "subset"

#include<bits/stdc++.h>
using namespace std;
const int N=39*20+5;

long long memo[N][N];

long long f(int i,int j){
    if(memo[i][j]!=-1)
        return memo[i][j];
    if(j==0)
        return memo[i][j]=1;
    if(i==0 or j<0 or (i*(i+1))/2<j)
        return memo[i][j]=0;
    return memo[i][j]=f(i-1,j-i)+f(i-1,j);
}

int n;

int main() {
    // freopen( &*(string(isim)+".in").begin() , "r" , stdin );
    // freopen( &*(string(isim)+".out").begin() , "w" , stdout );
    cin>>n;
    if((n*(n+1))%4){
        cout<<"0\n";
        return 0;
    }
    memset(memo,-1,sizeof(memo));
    
    f(n, (n*(n+1)) / 4);
    cout<<memo[n][(n*(n+1))/4]/2<<'\n';
}    