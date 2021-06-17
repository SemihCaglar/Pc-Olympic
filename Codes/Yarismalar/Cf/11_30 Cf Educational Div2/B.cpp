#include<semih/competitive.h>

int n;

void solve(){
    cin>>n;
    int i;
    for(i=1;;++i)
        if((i*(i+1))/2>=n)
            break;
    int top=(i*(i+1))/2;
    int res;
    if((top-n)==1){
        res=i+1;
    }
    else
        res=i;
    cout<<res<<'\n';
}

int main(){
    //test;
    fast;

    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}