#include<semih/competitive.h>

int n,d;
map<int,int> vis;

string fractionstodecimals(int n,int d){
    string ans="";
    while(n){
        vis[n]=ans.length();
        n*=10;
        char ekle='0'+n/d;
        n%=d;
        ans+=ekle;
        if(vis.count(n)){
            ans.insert(vis[n],"(");
            ans+=")";
            return ans;
        }

    }
    return ans;
}

void solve(){
    cin>>n>>d;
    string ans="";
    ans+=to_string(n/d);
    ans+=".";
    n=n%d;
    string bolum=fractionstodecimals(n,d);
    if(bolum=="")
        ans+="0";
    else
        ans+=bolum;
    for(int i=0;i<ans.length();++i){
        cout<<ans[i];
        if((i+1)%76==0)
            cout<<'\n';
    }
    if(ans.length()%76)
        cout<<'\n';
}