#include<semih/competitive.h>

const int N=3e5+5;
int t,n;
string s;

bool tunel[N];  // 0 sol, 1 sag.
int dp_r[N][2];
int dp_l[N][2];

int right(int ind,bool cift){ // cift ise true, degilse false.
    if(ind==n+1)
        return 0;    
        
    int &ref=dp_r[ind][cift];
    if(ref!=-1)
        return ref;

    bool sag=cift?1-tunel[ind]:tunel[ind];
    if(sag==1)
        return ref = 1+right(ind+1,1-cift);
    return 0;
}

int left(int ind, bool cift){
    if(ind==1)
        return 0;    
        
    int &ref=dp_l[ind][cift];
    if(ref!=-1)
        return ref;

    bool sol=cift?1-tunel[ind-1]:tunel[ind-1];
    if(sol==0)
        return ref = 1+left(ind-1,1-cift);
    return 0;
}

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>n>>s;
        for(int i=1;i<=n;++i)
            tunel[i]= s[i-1]=='L'?0:1;

        for(int i=0;i<=n+1;++i)
            dp_l[i][0]=dp_l[i][1]=dp_r[i][0]=dp_r[i][1]=-1;
        
        for(int i=1;i<=n+1;++i)
            cout<<left(i,false)+1+right(i,false)<<" ";
        cout<<"\n";
    }

    return 0;
}