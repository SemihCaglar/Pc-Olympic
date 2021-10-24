#include<semih/competitive.h>

ll t,n;

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>n;
        ll bir=0,sifir=0;
        for(int i=0;i<n;++i){
            int x;
            cin>>x;
            if(x==0)
                sifir++;
            if(x==1)
                bir++;
        }
        cout<<bir*(1LL<<sifir)<<"\n";
    }    

    return 0;
}