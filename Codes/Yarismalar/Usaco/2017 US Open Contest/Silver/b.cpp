#include<semih/competitive.h>

int n,m;
string gen[1005];
int cnt;

bool f(int x,int y,int z){
    unordered_set<string> st;
    for(int i=0;i<n;++i){
        string tmp="";
        tmp+=gen[i][x];
        tmp+=gen[i][y];
        tmp+=gen[i][z];
        st.insert(tmp);
    }
    for(int i=n;i<2*n;++i){
        string tmp="";
        tmp+=gen[i][x];
        tmp+=gen[i][y];
        tmp+=gen[i][z];
        if(st.count(tmp))
            return false;
    }
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
        for(int j=i+1;j<m;++j)
            for(int k=j+1;k<m;++k)
                cnt+=f(i,j,k);

    cout<<cnt<<"\n";

    return 0;
}