#define isim  "ljesnjak"

#include<bits/stdc++.h>
using namespace std;

int main() {
    //freopen( &*(string(isim)+".gir").begin() , "r" , stdin );
    //freopen( &*(string(isim)+".cik").begin() , "w" , stdout );
    string s;
    cin>>s;
    int cnt=0,i;
    #define neblm(a,b) s[i]==a&&s[i+1]==b
    for(i=0;i<s.length()-1;++i){
        if(i<s.length()-2&&s[i]=='d'&&s[i+1]=='z'&&s[i+2]=='='){
            cnt++;
            i+=2;
        }
        else if(neblm('c','=')||neblm('c','-')||neblm('d','-')||neblm('l','j')||neblm('n','j')||neblm('s','=')||neblm('z','=')){
            cnt++;
            i++;
        }
        else
            cnt++; 
    }
    if(i<s.length())
        cnt++;
    cout<<cnt;
}   