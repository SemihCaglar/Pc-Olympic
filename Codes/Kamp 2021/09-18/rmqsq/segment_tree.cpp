#include<semih/competitive.h>

const int N=2e5+5;
int n,q;
int a[N];
int tree[4*N];

int init(int k,int b,int e){
    if(b==e)
        return tree[k]=a[b];
    int mid=(b+e)/2;
    return tree[k] = min( init(2*k,b,mid) , init(2*k+1,mid+1,e) );
}

int query(int k,int b,int e,int l,int r){
    if(l>e or r<b)
        return INT_MAX;
    if(b==e)
        return tree[k];
    if(l<=b and r>=e)
        return tree[k];
    int mid=(b+e)/2;
    return min( query(2*k,b,mid,l,r) , query(2*k+1,mid+1,e,l,r) );
}

int main(){
    fast;
    // test();

    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];

    init(1,0,n-1);        

    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(1,0,n-1,l,r)<<"\n";
    }

    return 0;
}