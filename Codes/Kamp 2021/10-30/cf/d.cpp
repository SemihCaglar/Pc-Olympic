#include<semih/competitive.h>

ll t,x,y;

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>x>>y;
        if(x>y)
            cout<<x+y<<"\n";
        else if(x==y)
            cout<<x<<"\n";
        else{
            // n = x/2*k + y/2
            // n >= y - x + 1
            // x/2*k+y/2>=y-x+1
            // k >= (y-2x+2)/x (yukarı yuvarla)
            ll k = (y-2*x+2 +x-1)/x; 
            cout<<x/2*k+y/2<<"\n";
        }
    }    

    return 0;
}