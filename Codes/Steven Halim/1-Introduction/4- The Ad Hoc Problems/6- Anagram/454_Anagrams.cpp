#include<bits/stdc++.h>
using namespace std;
typedef pair<string,string> ss;

int t;
string s,tmp;
vector<ss> v;

bool pali(string a,string b){ // Aslında anagram fonksiyonu :d 
    int cnt[300]={};
    for(auto i:a)
        cnt[(int)i]++;
    for(auto i:b)
        cnt[(int)i]--;
    for(int i=0;i<300;++i)
        if(cnt[i])
            return false;
    return true;
}

int main(){
    cin>>t;
    getline(cin,s);
    getline(cin,s);

    while(t--){
        while(getline(cin,s),s!=""){
            tmp="";
            for(auto i:s)
                if(i!=' ')
                    tmp+=i;
            v.push_back(ss(s,tmp));
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();++i)
            for(int j=i+1;j<v.size();++j)
                if(pali(v[i].second,v[j].second))
                    cout<<v[i].first<<" = "<<v[j].first<<'\n';
        v.clear();
        if(t)
            cout<<'\n';
    }
}