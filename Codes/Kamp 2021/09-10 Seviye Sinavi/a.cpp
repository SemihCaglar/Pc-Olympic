#include<semih/competitive.h>

int n;
string s;
int ans;

int main(){
    fast;
    // test();

    cin>>n;    
    for(int i=0;i<n;++i){
        cin>>s;
        if(s[1]=='+')
            ans++;
        else
            ans--;
    }
    cout<<ans<<"\n";

    return 0;
}