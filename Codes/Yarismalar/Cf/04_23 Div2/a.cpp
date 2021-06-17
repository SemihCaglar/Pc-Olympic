#include<semih/competitive.h>

int t;
unsigned long long n;

int main(){
    // test();
    fast;
    cin>>t;
    while(t--){
        int sum=0;
        cin>>n;
        unsigned long long i;
        label:
        i=2050;
        for(;i*10<=n;i*=10);
        
        // dbg(n),dbg(i);
        if(n>=2050){
            sum+=n/i;
            n%=i;
            goto label;
        }
            
        if(n)
            cout<<-1<<"\n";
        else
            cout<<sum<<"\n";
    }
    return 0;
}