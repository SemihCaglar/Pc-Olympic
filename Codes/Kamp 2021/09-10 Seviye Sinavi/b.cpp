#include<semih/competitive.h>

string s;
map<char,int> mp;
vector<char> tek;

int main(){
    fast;
    // test();

    cin>>s;
    for(auto &i:s)
        mp[i]++,i=' ';
    for(auto i:mp)
        if(i.se%2==1){
            mp[i.fi]--;
            tek.pb(i.fi);
        }
    sort(all(tek));
    if(s.length()%2==1){
        if(tek.size()>1){
            s[s.length()/2]=tek[tek.size()/2];
            tek.erase(tek.begin()+tek.size()/2);
        }
        else{
            s[s.length()/2]=tek[0];
            tek.erase(tek.begin());
        }
    }
    for(int i=0;i<tek.size()/2;++i){
        mp[tek[i]]+=2;
    }
    int ind=0;
    for(auto i:mp){
        for(int j=0;j<i.se/2;++j,++ind)
            s[ind]=s[s.length()-ind-1]=i.fi;
    }
    
    cout<<s<<"\n";
    return 0;
}