#include<semih/competitive.h>

ii l,r;
int t,n;

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>n;
        map<ii,int> mp;
        l={INT_MAX,0},r={-1,0};
        for(int i=0;i<n;++i){
            int a,b,c;
            cin>>a>>b>>c;
            mp[ii(a,b)]=c;
            if(a<l.fi or a==l.fi and c<l.se)
                l={a,c};
            if(b>r.fi or b==r.fi and c<r.se)
                r={b,c};
            
            if(mp.count({l.fi,r.fi}))
                cout<<min( l.se+r.se , mp[{l.fi,r.fi}] )<<"\n";
            else
                cout<<l.se+r.se<<"\n";
        }
    }    

    return 0;
}