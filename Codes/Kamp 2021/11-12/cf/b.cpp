#include<semih/competitive.h>

int t,n;
string s;

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>n>>s;
        set<int> st;
        int bas=0,son=n-1;
        while(bas<son){
            while(s[son]=='1')
                son--;
            while(s[bas]=='0')
                bas++;
            if(bas>=son)
                break;
            st.insert(bas);
            st.insert(son);
            bas++,son--;
        }
        if(st.empty()){            
            cout<<0<<"\n";
            continue;
        }
        cout<<1<<"\n"<<st.size()<<" ";
        for(auto i:st)
            cout<<i+1<<" ";
        cout<<"\n";
    }    

    return 0;
}