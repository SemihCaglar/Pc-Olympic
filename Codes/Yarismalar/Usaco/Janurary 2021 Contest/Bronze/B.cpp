#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define test freopen("/home/semih/Desktop/Pc Olympic/test/test.in","r",stdin);freopen("/home/semih/Desktop/Pc Olympic/test/test.out","w",stdout)

int dp[2][2][1005][1005];

int f(int simdiki,int tamamlama,int tek,int cift){
    if( (tamamlama==1 and tek==1 and cift==0) or (tamamlama==0 and cift==1 and tek==0) )
        return 1;
    if(tamamlama==1 and tek==0 or tek<0 or cift<0 or tek==0 and cift==0)
        return INT_MIN;

    if(dp[simdiki][tamamlama][tek][cift]!=-1)
        return dp[simdiki][tamamlama][tek][cift];
    int res=-1;
    res=max(res, f(simdiki,tamamlama,tek,cift-1) );
    res=max(res, f(simdiki,(tamamlama+1)%2,tek-1,cift) );
    if(tamamlama==1)
        res=max(res, f((simdiki+1)%2,(simdiki+1)%2,tek-1,cift) +1 );
    else 
        res=max(res, f((simdiki+1)%2,(simdiki+1)%2,tek,cift-1) +1 );
    return dp[simdiki][tamamlama][tek][cift]=res;
}

int main(){
    fast;
    //test;

    int tek=0,cift=0;
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        if(a%2)
            tek++;
        else   
            cift++;
    }
    for(int i=0;i<2;++i)
        for(int j=0;j<2;++j)
            for(int k=0;k<n+5;++k)
                for(int a=0;a<n+5;++a)
                    dp[i][j][k][a]=-1;
    cout<<f(0,0,tek,cift);

}