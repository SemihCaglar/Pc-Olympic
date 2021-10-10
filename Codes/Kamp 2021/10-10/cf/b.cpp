#include<semih/competitive.h>

const int N=1e4+5;
int t;
int n;
bool a[N][6];

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        
        bool flag=false;
        cin>>n;
        for(int i=0;i<n;++i)
            for(int j=0;j<5;++j)
                cin>>a[i][j];

        for(int bir=0;bir<5;++bir)
            for(int iki=0;iki<5;++iki){
                if(bir==iki)
                    continue;
                bool belki=true;

                int x,y,z;
                x=y=z=0;
                for(int i=0;i<n;++i){
                    if(a[i][bir] and a[i][iki])
                        y++;
                    else if(a[i][bir]==0 and a[i][iki])
                        x++;
                    else if(a[i][bir] and a[i][iki]==0)
                        z++;
                    else  
                        belki=false;
                }
                if(x+y<n/2 or y+z<n/2)
                    belki=false;
                
                if(belki)
                    flag=true;
            }
        if(flag)
            cout<<"Yes\n";
        else
            cout<<"No\n";

    }

    return 0;
}