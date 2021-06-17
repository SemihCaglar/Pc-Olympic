#include<semih/competitive.h>

int n;

vector<string> ans;

int sign[10]; // 1 ise + 2 ise - 3 ise ' '

bool zero(string s){
    int sum=0,cur=0,sign=1;
    for(int i=0;i<s.length();++i){
        if(s[i]=='+' or s[i]=='-'){
            sum+=cur*sign;
            cur=0;
            sign=s[i]=='+'? 1: -1;
        }
        else if(s[i]!=' '){
            cur*=10;
            cur+=s[i]-'0';
        }
    }
    sum+=cur*sign;
    return !sum;
}

void check(){
    string s="";
    for(int i=1;i<n;++i){
        s+=i+'0';
        if(sign[i]==1)
            s+="+";
        else if(sign[i]==2)
            s+="-";
        else
            s+=" ";
    }
    s+=n+'0';
    if(zero(s))
        ans.pb(s);
}

void subset(int x){
    if(x==n){
        check();
        return;
    }
    sign[x]=1;
    subset(x+1);
    sign[x]=2;
    subset(x+1);
    sign[x]=3;
    subset(x+1);
}

void solve(){
    cin>>n;
    subset(1);
    sort(all(ans));
    cfor(i,ans)
        cout<<*i<<'\n';

}