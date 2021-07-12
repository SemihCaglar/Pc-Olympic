#include<semih/competitive.h>

int n;
string s;

void dfs(int x){
    if(x==s.length()){
        cout<<s<<"\n";
        return;
    }
    dfs(x+1);
    s[x]='1'-s[x]+'0';
    dfs(x+1);
}

int main(){
    fast;
    // test();

    cin>>n;    
    for(int i=0;i<n;++i)
        s+="0";
    dfs(0);
    
    return 0;
}