#include<semih/competitive.h>

int n,q;
string letter[]={"a","b","c","d","e","f"};
map<string,string> mp;
int cnt;

bool f(string s){
    while(s.length()!=1){
        string a=s.substr(0,2);
        if(mp.count(a)==false)
            return false;
        string tmp="";
        tmp+=mp[a];
        for(int i=2;i<s.length();++i)
            tmp+=s[i];
        s=tmp;
    }
    return s=="a";
}

void subset(string s){
    if(s.length()==n){
        if(f(s))
            cnt++;
        return;
    }
    for(auto i:letter)
        subset(s+i);
}

void solve(){
    freopen("/home/semih/Desktop/Pc Olympic/test/test.err","w",stderr);
    cin>>n>>q;
    forr(i,0,q){
        string a,b;
        cin>>a>>b;
        mp[a]=b;
    }
    subset("");
    cout<<cnt;
}