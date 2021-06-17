#include<semih/competitive.h>

const int N=505;
int ar[N],x,n;
 
void solve(){
    cin>>n>>x;
    forr(i,0,n)
        cin>>ar[i];
    if(is_sorted(ar,ar+n)){
        cout<<"0\n";
        return;
    }
    int ind=0,cnt=0;
    while(ind<n){
        int res;
        for(;ind<n and ar[ind]<=x;++ind);
        if(ind==n or is_sorted(ar,ar+n))
            break;
        cnt++;
        swap(x,ar[ind]);
        ind++;
    }
    if(is_sorted(ar,ar+n)==false)
        cout<<"-1\n";
    else
        cout<<cnt<<'\n';
}
 
int main(){
    test;
    fast;
 
    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}