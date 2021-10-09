#include<semih/competitive.h>

int n,p,cnt;

int main(){
    fast;
    // test();

    cin>>n>>p;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        if(x<p)
            cnt++;
    }    
    cout<<cnt<<"\n";

    return 0;
}