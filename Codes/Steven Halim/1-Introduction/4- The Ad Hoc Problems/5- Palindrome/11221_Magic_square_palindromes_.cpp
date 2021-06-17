#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;

char ar[N][N];
int kok;

string bir(){
    string tmp="";
    for(int i=0;i<kok;++i)
        for(int j=0;j<kok;++j)
            tmp+=ar[j][i];
    return tmp;
}
string iki(){
    string tmp="";
    for(int i=kok-1;i>=0;--i)
        for(int j=kok-1;j>=0;--j)
            tmp+=ar[i][j];
    return tmp;
}
string uc(){
    string tmp="";
    for(int i=kok-1;i>=0;--i)
        for(int j=kok-1;j>=0;--j)
            tmp+=ar[j][i];
    return tmp;
}

bool magic(string s){
    int n=s.length();
    kok=sqrt(n);
    if(kok*kok!=n)
        return false;
    for(int i=0,cnt=0;i<kok;++i)
        for(int j=0;j<kok;++j)
            ar[i][j]=s[cnt++];
    if(bir()==s and iki()==s and uc()==s)
        return true;
    return false;
}

string tmp,s;
int t,cnt;

int main(){
    cin>>t;
    getline(cin,tmp);
    while(t--){
        getline(cin,tmp);
        s="";
        for(auto i:tmp)
            if(i<='z' and i>='a')
                s+=i;
        bool b=magic(s);
        cout<<"Case #"<<++cnt<<":\n";
        if(b) cout<<kok<<'\n';
        else  cout<<"No magic :(\n";
    }
}