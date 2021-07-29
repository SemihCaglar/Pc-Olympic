#include<semih/competitive.h>

int t,n;
string s;

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>n;
        s.clear();
        if(n<6){
            for(int i=0;i<n;++i)
                s+='a'+i;
            cout<<s<<"\n";
            continue;
        }
        s+="cabc";
        n-=4;
        while(n>6)
            s+="abcabc",n-=6;
        for(int i=0;i+1<n;++i)
            s+='d'+i;
        s+="c";
        
        cout<<s<<"\n";
    }    

    return 0;
}