#include<semih/competitive.h>

int t,n;

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        ll sum=0;
        cin>>n;
        forr(i,0,n){
            int x;
            cin>>x;
            sum+=x;
        }
        if(sum>0){
            if(sum<n)
                cout<<1<<"\n";
            else
                cout<<sum-n<<"\n";
        }
        else
            cout<<1<<"\n";
            
    }

    return 0;
}