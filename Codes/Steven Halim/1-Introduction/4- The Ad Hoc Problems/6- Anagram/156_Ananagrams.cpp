#include<bits/stdc++.h>
using namespace std;
typedef pair<string,string> ss;

vector<ss> v;
string s,tmp;

bool anagram(string a,string b){
    int cnt[30]={0};
    for(auto i:a)
        cnt[i-'a']++;
    for(auto i:b)
        cnt[i-'a']--;
    for(int i=0;i<30;++i)
        if(cnt[i])
            return false;
    return true;
}

int main(){
    while(cin>>tmp,tmp!="#"){
        s="";
        for(int i=0;i<tmp.length();++i){
            if(tmp[i]=='I')
                s += 'i';
            else if(tmp[i]<='Z' and tmp[i]>='A')
                s += tmp[i]-'A'+'a';
            else   
                s += tmp[i];
        }
        v.push_back(ss(tmp,s));
    }
    sort(v.begin(),v.end());

    for(int i=0;i<v.size();++i){
        bool flag=true;
        for(int j=0;j<v.size();++j){
            if(i!=j and anagram(v[i].second,v[j].second)){
                flag=false;
                break;
            }
        }
        if(flag)
            cout<<v[i].first<<'\n';
    }
}