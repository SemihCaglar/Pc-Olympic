#include<semih/competitive.h>

string s;
unordered_map<char,int> mp;
int cnt;
bool tek=false;

int main(){
    fast;
    // test();

    cin>>s;
    for(auto i:s)
        mp[i]++;

    for(auto j:mp){
        int num=j.se;
        while(num>=2){
            s[cnt]=s[s.length()-1-cnt]=j.fi;
            num-=2;
            cnt++;
        }
        if(num==1){
            if(tek or s.length()%2==0){
                cout<<"NO SOLUTION\n";
                return 0;
            }
            s[s.length()/2]=j.fi;
            tek=true;
        }
    }
    cout<<s<<"\n";

    return 0;
}