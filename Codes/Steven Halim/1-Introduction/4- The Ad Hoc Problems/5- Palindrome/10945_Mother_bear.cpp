#include<bits/stdc++.h>
using namespace std;

bool pali(string s){
    for(int i=0;i<s.length()/2;++i)
        if(s[i]!=s[s.length()-1-i])
            return false;
    return true;
}

string s;

int main(){
    
    while(getline(cin,s),s!="DONE"){
        string tmp="";
        for(auto i:s){
            if(i<='z' and i>='a')
                tmp+=i;
            else if(i<='Z' and i>='A')
                tmp+=(char)(i-'A'+'a');
        }
        bool b=pali(tmp);
        if(b) cout<<"You won't be eaten!\n";
        else  cout<<"Uh oh..\n";
    }
}