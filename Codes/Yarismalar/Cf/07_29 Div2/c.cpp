#include<semih/competitive.h>

ll t,n,m;

ll neolur(ll x){
    ll sum=0;
    for(ll tmp=x/2;tmp;tmp/=2)
        if((tmp&n)==0)
            sum+=tmp;
    return sum;    
}

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>n>>m;
        if(n>m){
            cout<<0<<"\n";
            continue;
        }
        m-=n;
        m++;
        ll x=1;   
        while(x<=m)
            x*=2;
        while(neolur(x)<m)
            x*=2;
        ll sum=0;
        while(m>0){
            if(n&x){
                x/=2;
                continue;
            }
            ll tmp=neolur(x);
            if(tmp<m){
                m-=x;
                sum+=x;
            }
            x/=2;
        }
        cout<<sum<<"\n";
    }    

    return 0;
}