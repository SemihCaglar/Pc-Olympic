#include<semih/competitive.h>

int n;
ii a[305];
ll cnt;

int main(){
    fast;
    // test();

    cin>>n;
    for(int i=0;i<n;++i){
        int x,y;
        cin>>x>>y;
        a[i]={x,y};
    }    
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            for(int k=0;k<n;++k){
                if(i==j or i==k or j==k)
                    continue;
                ii x=a[i],y=a[j],z=a[k];
                ii dizi[3]={x,y,z};
                sort(dizi,dizi+3);
                if( (x.fi==y.fi and y.fi==z.fi) or (x.se==y.se and y.se==z.se) ){}
                else if( ( (dizi[1].se-dizi[0].se)*(dizi[2].fi-dizi[0].fi) ) == ( (dizi[1].fi-dizi[0].fi)*(dizi[2].se-dizi[0].se) ) ){}
                else    
                    cnt++;                
            }
    cout<<cnt/6<<"\n";

    return 0;
}