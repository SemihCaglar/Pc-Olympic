#include<semih/competitive.h>

int n,m;
int a[10005][8];

int main(){
    fast;
    // test();

    cin>>n>>m;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin>>a[i][j];

    bool flag=true;
    if( ( a[0][0]%7==0 ? 7 : a[0][0]%7 ) > 7-m+1 )
        flag=false;

    for(int i=0;i+1<m;++i)
        if(a[0][i]+1!=a[0][i+1])   
            flag=false;
    for(int i=1;i<n;++i)
        for(int j=0;j<m;++j)
            if(a[i][j]!=a[i-1][j]+7)
                flag=false;

    if(flag)
        cout<<"Yes\n";
    else
        cout<<"No\n"; 

    return 0;
}