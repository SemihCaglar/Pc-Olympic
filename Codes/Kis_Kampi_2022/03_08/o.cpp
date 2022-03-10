#include<semih/competitive.h>

const int N=4e4+5;
int n,k;
int ar[N];
int dp[N];
int dp_tmp[N];

int cost(int l, int r){

}

void solve(int l, int r, int optl, int optr){
    int m=(l+r)/2;
    ii ans={INT_MIN,INT_MIN};
    for(int k=optl+1;k<=min(m,optr);++k){
        int maybe=dp[k-1]+cost(k,m);
        ans=max(ans,{maybe,k});
    }
    dp_tmp[m]=ans.fi;
    int opt=ans.se;
    solve(l,m-1,optl,opt);
    solve(m+1,r,opt,optr);
}

int main(){
    fast;
    // test();

    cin>>n>>k;
    for(int i=0;i<n;++i)
        cin>>ar[i];
    
    map<int,bool> mp;

    int cnt=0;
    for(int i=0;i<n;++i){
        if(mp.count(ar[i])==0)
            cnt++;
        mp[ar[i]]=true;
        dp[i]=cnt;
    }
    for(int i=0;i<=k;++i)
    cdbg(dp,n);

    return 0;
}