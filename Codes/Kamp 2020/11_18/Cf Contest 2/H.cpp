#include<bits/stdc++.h>
using namespace std;
const int N=1e3+4;
int n;
map<string,long long> mp;
long long mx=LONG_LONG_MIN;
map<string,long long> mp2;
string isimler[N];
int sayilar[N];


int main(){
    cin>>n;
    
    for(int i=0;i<n;++i){
        string s;
        int x;
        cin>>s>>x;
        sayilar[i]=x;
        isimler[i]=s;
        mp[s]+=x; 
    }

    for(auto i:mp)
        mx=max(mx,i.second);
    int x;
    string s;
    for(int i=0;i<n;++i){
        x=sayilar[i];
        s=isimler[i];
        mp2[s]+=x;
        if(mp2[s]>=mx&&mp[s]==mx){
            cout<<s;
            return 0;
        } 
    }
    
}