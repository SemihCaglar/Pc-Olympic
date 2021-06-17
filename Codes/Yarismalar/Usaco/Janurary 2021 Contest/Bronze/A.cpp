#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

map<char,int> order;
string s;

bool kucuk(char a,char b){
    return order[a]<order[b];
}

int main(){
    fast;
    // freopen("/home/semih/Desktop/Pc Olympic/test/test.in","r",stdin);

    for(int i=1;i<=26;++i){
        char a;
        cin>>a;
        order[a]=i;
    }
    cin>>s;
    int cnt=1;
    for(int i=1;i<s.length();++i){
        char now=s[i],prev=s[i-1];
        if(kucuk(prev,now))
            continue;
        else
            cnt++;
    }
    cout<<cnt;

    
}