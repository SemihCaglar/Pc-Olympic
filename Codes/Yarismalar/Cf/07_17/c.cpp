#include<semih/competitive.h>

const int N=1e5+5;

int t,n;
int a[N],b[N];

int main(){
    fast;
    // test();

    cin>>t;
    while (t--){
        cin>>n;
        forr(i,1,n+1)
            cin>>a[i];
        forr(i,1,n+1)
            cin>>b[i];

        sort(a+1,a+n+1);
        reverse(a+1,a+n+1);
        sort(b+1,b+n+1);
        reverse(b+1,b+n+1);

        for(int i=2;i<=n;++i)
            a[i]+=a[i-1];
        for(int i=2;i<=n;++i)
            b[i]+=b[i-1];
        
        int cnt=0;
        ll suma=0,sumb=0;
        suma=a[n-n/4];
        sumb=b[n-n/4];
        while(suma<sumb){
            int oluru=n+1-(n+1)/4;
            suma=(cnt+1)*100+a[(oluru-cnt-1)];
            sumb=oluru>n-cnt?b[n-cnt]:b[oluru];
            n++;
            cnt++;
        }
        cout<<cnt<<"\n";
    }
        

    return 0;
}