/*
ID: semihca1
TASK: hamming
LANG: C++                 
*/
#define isim  "hamming"

#include<bits/stdc++.h>
using namespace std;

int n,b,d;
int sayilar[70];

int hamming_distance(int x,int y){
    int cnt=0;
    for(int i=0;i<b;++i)
        if( (x&(1<<i)) != (y&(1<<i)) )
            cnt++;
    return cnt;
}
bool gen(int x){
    for(int i=x-2;i>=0;--i)
        if(hamming_distance(sayilar[x-1],sayilar[i])<d)
            return false;
    if(x==n)
        return true;  
    
    int i=x==0?0:sayilar[x-1]+1;
    for(;i<=(1<<b);++i){
        sayilar[x]=i;
        if(gen(x+1))
            return true;
    }
    return false;
}

int main() {
    // freopen( &*(string(isim)+".in").begin() , "r" , stdin );
    // freopen( &*(string(isim)+".out").begin() , "w" , stdout );
    cin>>n>>b>>d;
    gen(0);
    cout<<sayilar[0];
    for(int i=1;i<n;++i){
        if(i%10==0)
            cout<<'\n';
        else
            cout<<' ';
        cout<<sayilar[i];
    }
    cout<<endl;
}    