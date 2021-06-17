#include<bits/stdc++.h>
using namespace std;

multiset<char> anahtar;
int cnt;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(auto i:s){
        if(i<='z'&&i>='a')
            anahtar.insert(i);
        else
        {
            if(anahtar.count(i-'A'+'a')){
                anahtar.erase(anahtar.find(i-'A'+'a'));
            }
            else
            {
                    cnt++;
            }
            
        }
        
    }
    cout<<cnt;
}