#include<semih/competitive.h>

const int N=2e5+5;
int t,n;
ll sum;
map<int,int> mp;

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>n;
        sum=0;
        mp.clear();
        for(int i=0;i<n;++i){
            int x;
            cin>>x;
            sum+=x;
            mp[x]++;
        }
        if(2*sum%n){
            cout<<0<<"\n";
            continue;
        }
        ll cevap=0;
        for(auto i:mp){
            ll x=i.fi;
            ll y=2*sum/n-x;
            if(x==y)
                cevap+=1LL*i.se*(i.se-1);
            else if(mp.count(y))
                cevap+=1LL*i.se*mp[y];
        }
        cout<<cevap/2<<"\n";
    }    

    return 0;
}