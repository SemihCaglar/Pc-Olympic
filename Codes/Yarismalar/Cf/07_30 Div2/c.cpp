#include<semih/competitive.h>
const int N=1e5+5;

int t,n;
int a[2][N];
int prefixsum[N];
int suffixsum[N];
int ans=INT_MAX;

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        ans=INT_MAX;
        cin>>n;
        for(int i=0;i<2;++i)
            for(int j=0;j<n;++j)
                cin>>a[i][j];
            
        prefixsum[0]=suffixsum[0]=0;
        for(int i=1;i<=n;++i)
            prefixsum[i]=prefixsum[i-1]+a[1][i-1];
        
        for(int i=1;i<=n;++i)
            suffixsum[i]=suffixsum[i-1]+a[0][n-i];

        for(int i=0;i<n;++i){
            int cevap=max(prefixsum[i],suffixsum[n-i-1]);
            ans=min(ans,cevap);
        }
        cout<<ans<<"\n";
    }    

    return 0;
}