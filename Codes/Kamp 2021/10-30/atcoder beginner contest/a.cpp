#include<semih/competitive.h>

string s;
set<char> st;

int main(){
    fast;
    // test();

    cin>>s;
    for(auto i:s)
        st.insert(i);
    if(st.size()==3)
        cout<<6<<"\n";
    else if(st.size()==2)
        cout<<3<<"\n";
    else
        cout<<1<<"\n";    

    return 0;
}