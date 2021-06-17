#include<semih/competitive.h>
const int N=1e5+5;

int n;
ll p;

void solve(){
    ii coo=_mp(n/2,n/2);
    int i=1;
    ll cnt=1;
    while(true){
        dbg(cnt);
        if(cnt<=p and p<=cnt+i)
            forr(j,0,i){
                if(cnt==p)
                    goto son;
                coo.fi--;
                cnt++;
            }
        else{
            cnt+=i;
            coo.fi-=i;
        }
        
        if(cnt<=p and p<=cnt+i)
            forr(j,0,i){
                if(cnt==p)
                    goto son;
                coo.se--;
                cnt++;
            }
        else{
            cnt+=i;
            coo.se-=i;
        }
        
        if(cnt<=p and p<=cnt+i+1)
            forr(j,0,i+1){
                if(cnt==p)
                    goto son;
                coo.fi++;
                cnt++;
            }
        else{
            cnt+=i+1;
            coo.fi+=i+1;
        }
        
        if(cnt<=p and p<=cnt+i+1)
            forr(j,0,i+1){
                if(cnt==p)
                    goto son;
                coo.se++;
                cnt++;
            }
        else{
            cnt+=i+1;
            coo.se+=i+1;
        }
        i+=2;
    }
    son:
    cout<<"Line = "<<n-coo.fi<<", column = "<<coo.se+1<<".\n";
}

int main(){
    test;
    fast;

    int t=1;
    // cin>>t;
    while(cin>>n>>p,n or p)
        solve();
    return 0;
}