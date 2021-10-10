#include<semih/competitive.h>

int dp[3][105];
int t,n;
char tuzak[3][105];
bool gray[3][105];

int intable(int x,int y){
    if(x<=2 and x>=1 and y<=n and y>=1 and tuzak[x][y]=='0') 
        return true;
    return false;
}

int f(int x,int y){
    if(gray[x][y]==true)
        return 0;
    if(dp[x][y]!=-1)
        return dp[x][y];
    
    if(x==2 and y==n)
        return 1;
    
    gray[x][y]=true;
    int ans=0;
    for(int i=0;i<2;++i){
        if(intable(x+1,y+i))
            ans=max(ans,f(x+1,y+i));
        if(intable(x-1,y+i))
            ans=max(ans,f(x-1,y+i));
    }
    if(intable(x,y+1))
        ans=max(ans,f(x,y+1));
    gray[x][y]=false;
    return dp[x][y]=ans;
}

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<=n;++i)
            dp[0][i]=dp[1][i]=dp[2][i]=-1;
        
        for(int i=1;i<=2;++i)
            for(int j=1;j<=n;++j)
                cin>>tuzak[i][j];
        if(f(1,1))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    

    return 0;
}