#include<semih/competitive.h>

int t,a,b,c;

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        if((a+c-2*b)%3==0)
            cout<<0<<"\n";
        else
            cout<<1<<"\n";    
    }

    return 0;
}