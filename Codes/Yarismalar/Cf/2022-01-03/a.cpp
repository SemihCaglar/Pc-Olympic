#include<semih/competitive.h>

int t,n,k;
bool ans[45][45];

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>n>>k;
        if( ( (n+1)/2 ) < k ){
            cout<<-1<<"\n";
            continue;
        }
        for(int i=0;(i/2)+1<=k;i+=2)
            ans[i][i]=true;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(ans[i][j])
                    cout<<"R";
                else
                    cout<<".";
            }
            cout<<"\n";
        }
        for(int i=0;i<45;++i)
            for(int j=0;j<45;++j)
                ans[i][j]=false;
    }    

    return 0;
}