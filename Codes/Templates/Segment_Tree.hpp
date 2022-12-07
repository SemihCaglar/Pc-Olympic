template<class T, class U> 
struct segTree{
    vector<T> ar, tree;
    vector<U> lazy;
    T invalid=LLONG_MAX;
    U empty_lazy=0;
    T merge_node(T x, T y){ return min(x,y); }
    U merge_lazy(U x, U y){ return y; }
    void apply(int k, int l, int r){
        tree[k]=lazy[k];
    }

    segTree(){}
    segTree(vector<T> &Ar){
        ar=Ar;
        tree.resize(ar.size()*4);
        lazy.resize(ar.size()*4);
        build(1,0,ar.size()-1);
    }
    #define m ((l+r)>>1)
    T build(int k, int l, int r){
        lazy[k]=empty_lazy;
        if(l==r) return tree[k]=ar[l];
        return tree[k]=merge_node(build(2*k,l,m),build(2*k+1,m+1,r));
    }
    void push(int k, int l, int r){
        if(lazy[k]==empty_lazy) return;
        apply(k,l,r);
        if(l!=r){
            lazy[2*k]=merge_lazy(lazy[2*k],lazy[k]);
            lazy[2*k+1]=merge_lazy(lazy[2*k+1],lazy[k]);
        }
        lazy[k]=empty_lazy;
    }
    T query(int k, int l, int r, int b, int e){
        if(b>r or e<l) return invalid;
        push(k,l,r);
        if(l>=b and r<=e) return tree[k];
        return merge_node(query(2*k,l,m,b,e),query(2*k+1,m+1,r,b,e));
    }
    void update(int k, int l, int r, int b, int e, U upd){
        push(k,l,r);
        if(b>r or e<l) return;
        if(l>=b and r<=e){
            lazy[k]=upd; push(k,l,r);
            return;
        }
        update(2*k,l,m,b,e,upd),update(2*k+1,m+1,r,b,e,upd);
        tree[k]=merge_node(tree[2*k],tree[2*k+1]);
    }
    #undef m
};