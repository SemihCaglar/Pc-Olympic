#include<semih/competitive.h>

int n,m;
string gen[1005];
int cnt;

bool f(int x){
    unordered_set<char> st;
    for(int i=0;i<n;++i)
        st.insert(gen[i][x]);
    for(int i=n;i<2*n;++i)
        if(st.count(gen[i][x]))
            return false;
    return true;
}

int main(){
    fast;
    test("cownomics");
    // test();

    cin>>n>>m;
    for(int i=0;i<2*n;++i)
        cin>>gen[i];

    for(int i=0;i<m;++i)
        cnt+=f(i);

    cout<<cnt<<"\n";

    return 0;
}