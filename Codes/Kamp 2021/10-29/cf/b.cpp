#include<semih/competitive.h>

int t;
typedef unsigned long long int ulli;
ulli n,k;

int main(){
    fast;
    // test();

    cin>>t;    
    while(t--){
        cin>>n>>k;
        ulli sum=0;
        ulli kuvvet=1;
        while(kuvvet<=k and kuvvet<n)
            kuvvet*=2,sum++;
        if(kuvvet>n)
            sum+=0;
        else
            sum+=(n-kuvvet+k-1)/k;
        cout<<sum<<"\n";
    }

    return 0;
}