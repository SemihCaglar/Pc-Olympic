#include<bits/stdc++.h>
using namespace std;

bool cmp(char s1,char s2){
    char c1,c2;
    if(s1<='Z' and s1>='A') c1=s1-'A'+'a';
    else c1=s1;
    if(s2<='Z' and s2>='A') c2=s2-'A'+'a';
    else c2=s2;

    if(c1==c2)
        return s1<s2;
    return c1<c2;
}

int t;
string s;

int main(){
    cin>>t;
    while(t--){
        cin>>s;
        sort(s.begin(),s.end(),cmp);
        do
            cout<<s<<'\n';
        while( next_permutation(s.begin(),s.end(),cmp) );
    }
}