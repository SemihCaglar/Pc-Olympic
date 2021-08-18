#include<semih/competitive.h>

typedef unsigned long long int ulli;

int t,n;

int f(ulli a,ulli b){
    if(a==b)
        return 0;
    string s1=to_string(a);
    string s2=to_string(b);
    int cnt=0;
    int j=0,i=0;
    for(;i<s2.length();++i){
        bool flag=false;
        for(;j<s1.length();++j,cnt++){
            if(s1[j]==s2[i]){
                flag=true;
                break;
            }
        }
        if(j!=s1.length())
            ++j;
        if(j>=s1.length()){
            cnt+=s2.length()-i-flag;
            break;
        }
    }
    cnt+=s1.length()-j;
    return cnt;
}

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>n;
        int mn=INT_MAX;
        for(ulli i=1;i<=1e18;i*=2){
            mn=min(mn,f(n,i));
        }
        cout<<mn<<"\n";
    }    

    return 0;
}