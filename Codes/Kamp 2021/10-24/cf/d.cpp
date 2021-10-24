#include<semih/competitive.h>

const int N=1e2+5;
int t,n;
ii a[N];
int ans[N];

ii f(ii x){
    int ebob=__gcd(x.fi,x.se);
    if((x.fi<0)==(x.se<0))
        return {x.se/ebob,x.fi/ebob*-1};
    return {x.se/ebob,x.fi/ebob*-1};
}

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;++i)
            a[i].se=i;
        for(int i=0;i<n;++i)
            cin>>a[i].fi;
        
        if(n%2==0){
            for(int i=1;i<n;i+=2){
                ii tmp=f({a[i].fi,a[i-1].fi});
                ans[a[i].se]=tmp.fi;
                ans[a[i-1].se]=tmp.se;
            }
        }

        else{
            sort(a,a+n);
        
            if(a[0].fi<0 and a[n-1].fi>0){
                ii tmp=f({a[0].fi+a[n-1].fi,a[1].fi});
                ans[a[1].se]=tmp.se;
                ans[a[0].se]=ans[a[n-1].se]=tmp.fi;

                for(int i=3;i+1<n;i+=2){
                    ii tmp=f({a[i].fi,a[i-1].fi});
                    ans[a[i].se]=tmp.fi;
                    ans[a[i-1].se]=tmp.se;
                }
            }
                
            else if(a[0].fi<0 and a[n-1].fi<0){
                ii tmp=f({a[n-1].fi+a[n-2].fi,a[n-3].fi});
                ans[a[n-3].se]=tmp.se;
                ans[a[n-1].se]=ans[a[n-2].se]=tmp.fi;

                for(int i=1;i+3<n;i+=2){
                    ii tmp=f({a[i].fi,a[i-1].fi});
                    ans[a[i].se]=tmp.fi;
                    ans[a[i-1].se]=tmp.se;
                }
            }

            else{
                ii tmp=f({a[0].fi+a[1].fi,a[2].fi});
                ans[a[2].se]=tmp.se;
                ans[a[0].se]=ans[a[1].se]=tmp.fi;

                for(int i=4;i<n;i+=2){
                    ii tmp=f({a[i].fi,a[i-1].fi});
                    ans[a[i].se]=tmp.fi;
                    ans[a[i-1].se]=tmp.se;
                }
            }

        }

        for(int i=0;i<n;++i)
            cout<<ans[i]<<" ";
        cout<<"\n";

    }    

    return 0;
}