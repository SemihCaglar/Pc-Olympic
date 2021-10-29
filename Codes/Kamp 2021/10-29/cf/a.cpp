#include<semih/competitive.h>

int t;
string s;

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>s;
        if(s[0]!=s[s.length()-1])
            s[s.length()-1]=s[0];
        cout<<s<<"\n";
    }    

    return 0;
}