#include<semih/competitive.h>

int n;
set<int> st;

int main(){
    fast;
    // test();

    cin>>n;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        st.insert(x);
    }    
    cout<<st.size()<<"\n";

    return 0;
}