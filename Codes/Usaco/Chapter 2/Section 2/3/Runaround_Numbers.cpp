/*
ID: semihca1
TASK: runround
LANG: C++                 
*/
#define isim  "runround"

#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ulli;

bool unique(ulli x){
    string s;
    {
        stringstream ss;
        ss << x;
        ss >> s;
    }
    bool vis[10]={};
    for(auto i:s){
        if(vis[i-'0'])
            return false;
        vis[i-'0']=true;
    }
    return true;
}

bool roundaround(ulli x){
    string s;
    {
        stringstream ss;
        ss << x;
        ss >> s;
    }
    bool vis[s.length()+2]={};
    int i=1,cnt=0;
    while(true){
        int sayi=s[i-1]-'0';
        int hedef=(sayi+i)%s.length();
        if(hedef==0)
            hedef=s.length();
        if(vis[hedef])
            return false;
        if(cnt==s.length()-1 and hedef==1)
            return true;
        vis[hedef]=true;
        cnt++;
        i=hedef;
    }
}

int main() {
    // freopen( &*(string(isim)+".in").begin() , "r" , stdin );
    // freopen( &*(string(isim)+".out").begin() , "w" , stdout );
    ulli n;
    cin>>n;
    for(ulli i=n+1;;i++){
        if(unique(i) and roundaround(i)){
            cout<<i<<endl;
            return 0;
        }
    }
}    