#include<semih/competitive.h>

int k,n;
map<int,int> mp[15];
int cnt;

int main(){
    fast;
    test("gymnastics");
    // test();

    cin>>k>>n;
    for(int i=0;i<k;++i)
        for(int j=0;j<n;++j){
            int x;
            cin>>x;
            mp[i][x-1]=j;
        }    

    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j){
            bool flag=true;
            for(int t=0;t<k;++t)
                if(mp[t][i]>=mp[t][j])
                    flag=false;
            cnt+=flag;
        }
    cout<<cnt<<"\n";

    return 0;
}