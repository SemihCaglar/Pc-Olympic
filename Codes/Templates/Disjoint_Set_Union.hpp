class DSU{

    private:
    int dad[105];

    public:
    DSU(){
        for(int i=0;i<105;++i)
            dad[i]=i;
    }
    int find(int x){
        if(x==dad[x])
            return x;
        return dad[x]=find(dad[x]);
    }
    void set(int a,int b){
        a=find(a);
        b=find(b);
        dad[a]=b;
    }
    bool same(int a,int b){
        return find(a)==find(b);
    }

};