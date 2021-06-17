/*
ID: semihca1
TASK: preface
LANG: C++                 
*/
#define isim  "preface"

#include<bits/stdc++.h>
using namespace std;

map<int,char> mp={ {1,'I'},{5,'V'},{10,'X'},{50,'L'},{100,'C'},{500,'D'},{1000,'M'},{5000,'S'} };
map<int,int> help={ {1,1},{5,1},{10,1},{50,10},{100,10},{500,100},{1000,100},{5000,1000} };

int N;
map<char,int> ans;

void f(int n){
    while(n){
        pair<int,char> onceki;
        for(auto i:mp){
            if(i.first>n){
                auto prev=make_pair(help[i.first],mp[help[i.first]]);
                if(i.first-prev.first<=n){
                    n-=i.first-prev.first;
                    ans[i.second]++;
                    ans[prev.second]++;
                }
                else{
                    int div=n/onceki.first;
                    n-=div*onceki.first;
                    ans[onceki.second]+=div;
                }
                break;
            }
            else if(i.first==n){
                ans[i.second]++;
                n-=i.first;
                break;
            }
            onceki=i;
        }
    }
}

int main() {
    // freopen( &*(string(isim)+".in").begin() , "r" , stdin );
    // freopen( &*(string(isim)+".out").begin() , "w" , stdout );
    cin>>N;
    for(int i=1;i<=N;++i)
        f(i);
    
    for(auto i:mp){
        if(ans.count(i.second)==0)
            break;
        cout<<i.second<<' '<<ans[i.second]<<'\n';
    }
}    