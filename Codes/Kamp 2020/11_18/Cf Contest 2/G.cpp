#include<bits/stdc++.h>
using namespace std;

int n;
map<string,int> mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;++i){
        string s;
        cin>>s;
        if(mp.count(s)==0){
            cout<<"OK\n";
        }
        else{
            cout<<s<<mp[s]<<'\n';
        }
        mp[s]++;
    }
}