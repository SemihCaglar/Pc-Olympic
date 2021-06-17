#include<semih/competitive.h>

class segmentTree{
    public:
        segmentTree(int n,int *ar){
            this->ar=ar;
            this->n=n;
            tree=(int*)malloc(4*n*sizeof(int));
        }
        ~segmentTree(){
            free(tree);
        }
        int init(int k,int b,int e,int depth){
            if(b==e)
                return tree[k]=ar[b];
            int mid=(b+e)/2;
            int left=init(k*2,b,mid,depth+1);
            int right=init(k*2+1,mid+1,e,depth+1);
            return tree[k]=(depth-n+1)%2?left|right:left^right;
        }
        int change(int k,int b,int e,int ind,int val,int depth){
            if(ind<b or ind>e)
                return tree[k];
            if(b==e)
                return tree[k]=val;
            int mid=(b+e)/2;
            int left=change(k*2,b,mid,ind,val,depth+1);
            int right=change(k*2+1,mid+1,e,ind,val,depth+1);
            return tree[k]=(depth-n+1)%2?left|right:left^right;
        }
        int *tree;
        int *ar;
        int n;
};

void solve(){
    int n,m;
    cin>>n>>m;
    int N=1<<n;
    int ar[N+5];
    forr(i,1,N+1)
        cin>>ar[i];
    
    segmentTree seg(N,ar);
    seg.n=n;

    seg.init(1,1,N,1);

    forr(i,0,m){
        int ind,val;
        cin>>ind>>val;
        seg.change(1,1,N,ind,val,1);
        cout<<seg.tree[1]<<'\n';
    }
}