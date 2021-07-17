#include<semih/competitive.h>

int n;
int a[105];
ii dp[205][205][2];

ii f(int b,int e,bool t){
    if(dp[b][e][t].fi or dp[b][e][t].se)
        return dp[b][e][t];
    if(b==e){
        if(t==0)
            return ii(a[b],0);
        return ii(0,a[b]);
    }
    ii left=f(b+1,e,!t);
    ii right=f(b,e-1,!t);
    if(t==0){
        if(left.fi+a[b]>right.fi+a[e])
            return dp[b][e][t]=ii(left.fi+a[b],left.se);
        return dp[b][e][t]=ii(right.fi+a[e],right.se);
    }
    if(left.se+a[b]>right.se+a[e])
        return dp[b][e][t]=ii(left.fi,left.se+a[b]);
    return dp[b][e][t]=ii(right.fi,right.se+a[e]);
}

int main(){
    fast;
    // test("game1");

    cin>>n;
    forr(i,0,n)
        cin>>a[i];
    
    ii ans=f(0,n-1,0);
    cout<<ans.fi<<sp<<ans.se<<"\n";

    return 0;
}