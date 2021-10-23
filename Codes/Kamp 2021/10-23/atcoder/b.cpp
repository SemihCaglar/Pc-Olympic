#include<semih/competitive.h>

int h,w;
int a[55][55];

int main(){
    fast;
    // test();

    cin>>h>>w;
    for(int i=1;i<=h;++i)
        for(int j=1;j<=w;++j)
            cin>>a[i][j];
        
    bool flag=true;
    for(int i=1;i<=h;++i)
        for(int j=1;j<=w;++j)
            for(int x=i+1;x<=h;++x)
                for(int y=j+1;y<=w;++y)
                    if(a[i][j]+a[x][y]>a[x][j]+a[i][y])
                        flag=false;
    if(flag)
        cout<<"Yes\n";
    else
        cout<<"No\n";

    return 0;
}