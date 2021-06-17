#include<semih/competitive.h>

int k,n;
int primes[105];
int start[105];
int humble[100005];

void solve(){
    cin>>k>>n;
    forr(i,0,k)
        cin>>primes[i];
    int found=0;
    int mn=INT_MAX;
    forr(i,0,k)
        mn=min(mn,primes[i]);
    humble[0]=mn;
    found++;
    
    while(found<n){
        int ans=INT_MAX;

        forr(i,0,k){
            mn=INT_MAX;
            int asal=primes[i];
            if(asal>humble[found-1]){
                mn=asal;
                goto son;
            }
            for(int j=start[i];j<found;++j){
                if(asal*humble[j]>humble[found-1]){
                    start[i]=j;
                    mn=asal*humble[j];
                    break;
                }
            }
            son:
            ans=min(ans,mn);
        }
        humble[found++]=ans;
    }
    cout<<humble[n-1];
    
}