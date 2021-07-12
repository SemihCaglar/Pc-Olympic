#include<semih/competitive.h>

string s;
int fact[10];
map<char,int> mp; 

void dfs(int x){
    if(x==s.length()){
        cout<<s<<"\n";
        return;
    }
    for(auto &i:mp)
        if(i.se){
            s[x]=i.fi;
            i.se--;
            dfs(x+1);
            i.se++;
        }
}

int main(){
    fast;
    // test();

    cin>>s;
    for(auto i:s)
        mp[i]++;

    fact[1]=1;
    for(int i=2;i<=8;++i)
        fact[i]=fact[i-1]*i;    

    int ans=fact[s.length()];
    for(auto i:mp)
        ans/=fact[i.se];
    cout<<ans<<"\n";

    dfs(0);

    return 0;
}