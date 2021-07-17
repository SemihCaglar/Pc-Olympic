#include<semih/competitive.h>

int t;
string n;

int main(){
    fast;
    // test();
    cin>>t;
    while(t--){
        int mx=1;
        cin>>n;
        for(auto i:n)
            mx=max(mx,i-'0');
        cout<<mx<<"\n";
    }

    return 0;
}