#include<semih/competitive.h>

int t,n;
string s;

int f(string s,char c){
    int cnt=0;
    int bas=0,son=s.length()-1;
    while(bas<son){
        if(s[bas]!=s[son]){
            if(s[bas]==c)
                bas++;
            else if(s[son]==c)
                son--;
            else
                return -1;
            cnt++;
        }
        else
            bas++,son--;
    }
    return cnt;
}

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        int mn=INT_MAX;
        cin>>n>>s;
        for(char i='a';i<='z';++i)
            if(f(s,i)!=-1)
                mn=min(mn,f(s,i));
        if(mn==INT_MAX)
            cout<<-1<<"\n";
        else
            cout<<mn<<"\n";
    }    

    return 0;
}