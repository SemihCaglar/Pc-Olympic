#include<bits/stdc++.h>
using namespace std;

map<char,char> ters={ {'A','A'},{'E','3'},{'H','H'},{'I','I'},{'J','L'},{'L','J'},{'M','M'},{'O','O'},
{'S','2'},{'T','T'},{'U','U'},{'V','V'},{'W','W'},{'X','X'},{'Y','Y'},{'Z','5'},{'1','1'},{'2','S'},
{'3','E'},{'5','Z'},{'8','8'} };

bool palind(string s){
    for(int i=0;i<=(s.length()-1)/2;++i)
        if(s[i]!=s[s.length()-1-i])
            return false;
    return true;
}

bool mirror(string s){
    for(int i=0;i<=(s.length()-1)/2;++i)
        if(ters.count(s[i])==0 or ters[s[i]]!=s[s.length()-1-i])
            return false;
    return true;
}

string s;

int main(){
    while(cin>>s){
        cout<<s<<" -- is ";
        bool pal=palind(s),mir=mirror(s);
        if(pal and mir)
            cout<<"a mirrored palindrome.";
        else if(pal)
            cout<<"a regular palindrome.";
        else if(mir)
            cout<<"a mirrored string.";
        else
            cout<<"not a palindrome.";
        cout<<"\n\n";
    }
}