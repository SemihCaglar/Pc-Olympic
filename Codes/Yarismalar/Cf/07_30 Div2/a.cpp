#include<semih/competitive.h>

int t;
typedef unsigned long long int ulli;
ulli n;

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>n;
        if(n<=6){
            cout<<"15\n";
            continue;
        }
        if(n%2==1)
            n++;
        cout<<n*5/2<<"\n";
    }    

    return 0;
}