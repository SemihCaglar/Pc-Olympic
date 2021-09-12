#include<semih/competitive.h>

int ans=-1;
int n;

bool f(string s){
    if(s.length()%2==0)
        return false;
    string tmp="";
    for(int i=0;i<s.length()/2+1;++i)
        tmp+='1';
    for(int i=0;i<s.length()/2;++i)
        tmp+='0';
    return s==tmp;
}

bool metal(int x){
    string s="";
    int i=0;
    if(x&1){
        x-=1;
        s+='1';
    }
    else
        s+='0';
    while(x){
        if(x&(2<<i)){
            s+='1';
            x-=(2<<i);
        }
        else
            s+='0';
        i++;
    }
    reverse(all(s));
    return f(s);
}

int main(){
    fast;
    // test();

    cin>>n;
    for(int i=1;i<=n;++i){
        if(n%i==0 and metal(i))
            ans=i;
    }
    cout<<ans<<"\n";

    return 0;
}