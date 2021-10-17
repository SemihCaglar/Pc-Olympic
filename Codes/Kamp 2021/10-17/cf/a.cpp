#include<semih/competitive.h>

const int N=105;
int t,n,a[N];

bool asal(int x){
    if(x==1)
        return false;
    for(int i=2;i*i<=x;++i)
        if(x%i==0)
            return false;
    return true;
}

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        int sum=0;
        int flag=-1;
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>a[i];
            sum+=a[i];
        }
        if(asal(sum)==false){
            cout<<n<<"\n";
            for(int i=1;i<=n;++i)
                cout<<i<<" ";
            cout<<"\n";
            continue;
        }
        for(int i=0;i<n;++i){
            if(asal(sum-a[i])==false)
                flag=i+1;
        }
        if(flag!=-1){
            cout<<n-1<<"\n";
            for(int i=1;i<=n;++i)
                if(i!=flag) 
                    cout<<i<<" ";
        }
        else{
            cout<<n-2<<"\n";
            for(int i=3;i<=n;++i)
                cout<<i<<" ";
        }
        cout<<"\n";
    }

    return 0;
}