/*
ID: semihca1
TASK: palsquare
LANG: C++                 
*/
#define isim "palsquare"

#include<bits/stdc++.h>
using namespace std;
int b;
string convert(int a){
    string s="";
    int i=1,cnt=1;
    for(;i*b<=a;i*=b,++cnt);
    while(cnt--){
        if(a>=i){
            int tmp=a/i;
            char rakam;
            if(tmp>=10)
                rakam='A'+tmp-10;
            else
                rakam='0'+tmp;
            s+=rakam;
            a-=tmp*i;
        }
        else
            s+='0';
        i/=b;
    }
    return s;
}

bool check(string s){
    for(int i=0;i<s.length()/2;++i)
        if(s[i]!=s[s.length()-1-i])
            return false;
    return true;
}

int main() {
    freopen( &*(string(isim)+".in").begin(),"r",stdin);
    freopen( &*(string(isim)+".out").begin(),"w",stdout);
    cin>>b;
    for(int i=1;i<=300;++i){
        string kare=convert(i*i);
        if(check(kare))
            cout<<convert(i)<<' '<<kare<<endl;
    }
}    