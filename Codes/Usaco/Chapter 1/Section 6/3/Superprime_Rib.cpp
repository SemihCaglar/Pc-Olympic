/*
ID: semihca1
TASK: sprime
LANG: C++                 
*/
#define isim  "sprime"

#include<bits/stdc++.h>
using namespace std;
int n;

bool asal(int n){
    for(int i=2;i*i<=n;++i)
        if(n%i==0)
            return false;
    return true;
}

void dfs(int x,int number){
    if(x==n){
        if(asal(number)){
            cout<<number<<'\n';
        }
        return;
    }
    if(x==0)
        dfs(1,2);
    for(int i=1;i<10;i+=2){
        if(x==0&&i==1)
            continue;
        int sayi=number*10+i;
        if(asal(sayi))
            dfs(x+1,sayi);
    }
}

int main() {
    // freopen( &*(string(isim)+".in").begin() , "r" , stdin );
    // freopen( &*(string(isim)+".out").begin() , "w" , stdout );
    cin>>n;
    dfs(0,0);
}    