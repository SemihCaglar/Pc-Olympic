#include<semih/competitive.h>
typedef long long int ulli;

bool a[65];
ulli dp[65][2];

ulli f(int n,bool logic){
    if(dp[n][logic]!=-1)
        return dp[n][logic];
    if(n==0)
        return 1;
    ulli cevap=0;
    if(a[n-1]==1){ // AND ise
        if(logic==true)
            cevap=f(n-1,true);
        else
            cevap=f(n-1,true)+2*f(n-1,false);
    }
    else{ // OR ise
        if(logic==true)
            cevap=f(n-1,false)+2*f(n-1,true);
        else
            cevap=f(n-1,false);
    }
    return dp[n][logic]=cevap;
}

void solve(){
    freopen("/home/semih/Desktop/Pc Olympic/test/test.err","w",stderr);
    int n;
    cin>>n;
    forr(i,0,n){
        string s;
        cin>>s;
        if(s=="AND")
            a[i]=1;
    }
    forr(i,0,n+1)
        forr(j,0,2)
            dp[i][j]=-1;
    cout<<f(n,true);
}