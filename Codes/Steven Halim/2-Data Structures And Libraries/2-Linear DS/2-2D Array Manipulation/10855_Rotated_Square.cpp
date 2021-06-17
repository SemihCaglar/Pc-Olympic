#include<competitive.h>
const int maxn=1e3+5;

int N,n;

int c0,c90,c180,c270;
char ar[maxn][maxn],arr[maxn][maxn];

void rotate(int &i,int &j){
    int itmp=i;
    i=n-j-1;
    j=itmp;
}

bool r0(int a,int b,int k){
    forr(i,0,n)
        forr(j,0,n){
            int x=i,y=j;
            forr(s,0,k)
                rotate(x,y);
            if(ar[a+i][b+j]!=arr[x][y])
                return false;
        }
    return true;
}

void solve(){
    c0=c90=c180=c270=0;
    forr(i,0,N)
        forr(j,0,N)
            cin>>ar[i][j];
    forr(i,0,n)
        forr(j,0,n)
            cin>>arr[i][j];
    
    forr(a,0,N-n+1)
        forr(b,0,N-n+1){
            c0+=r0(a,b,0);
            c90+=r0(a,b,1);
            c180+=r0(a,b,2);
            c270+=r0(a,b,3);
        }        
    cout<<c0<<sp<<c90<<sp<<c180<<sp<<c270<<'\n';
}

int main(){
    test;
    fast;

    int t=1;
    // cin>>t;
    while(cin>>N>>n, N or n)
        solve();
    return 0;
}