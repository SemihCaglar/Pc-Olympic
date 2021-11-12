#include<semih/competitive.h>

int t,n;
string s;

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>n>>s;
        int ans=-1;
        for(int i=2;i<=10;++i){
            for(int j=0;j+i-1<n;++j){
                int a,b,c;
                a=b=c=0;
                for(int k=0;k<i;++k){
                    if(s[j+k]=='a')
                        a++;
                    else if(s[j+k]=='b')
                        b++;
                    else
                        c++;
                }
                if(a>b and a>c and ans==-1)
                    ans=i;
            }
        }
        cout<<ans<<"\n";
    }    

    return 0;
}