#include<semih/competitive.h>

string s;

void solve(){
    if(next_permutation(all(s)))
        cout<<s<<'\n';
    else
        cout<<"No Successor\n";

}

int main(){
    test;
    fast;

    int t=1;
    // cin>>t;
    while(cin>>s,s!="#")
        solve();
    return 0;
}