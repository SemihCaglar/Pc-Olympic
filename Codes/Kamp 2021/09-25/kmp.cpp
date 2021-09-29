#include<semih/competitive.h>

const int N=2e6+5;
string a,b;
int pi[N];
int ans;

int main(){
    fast;
    // test();

    cin>>a>>b;
    string s=b+"#"+a;
    pi[0]=0;
    for(int i=1;i<s.length();++i){
        int k=pi[i-1];
        while(k!=0 and s[k]!=s[i])
            k=pi[k-1];
        pi[i] = k+(s[i]==s[k]);
        
        if(pi[i]==b.length())
            ans++;
    }     
    cout<<ans<<"\n";

    return 0;
}