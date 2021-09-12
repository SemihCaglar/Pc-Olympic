#include<semih/competitive.h>

const int N=2e5+5;
int n,m,k,q;
map<int,int> hazine;
int safe[N];
int ans;

int main(){
    fast;
    // test();

    cin>>n>>m>>k>>q;
    for(int i=0;i<k;++i){
        int x,y;
        cin>>x>>y;
        hazine[x]=y;
    }
    for(int i=0;i<q;++i)
        cin>>safe[i];
    sort(safe,safe+q);

    int pos=hazine[1];
    ans+=pos-1;

    for(int i=2;i<=n;++i){
        int treasure=hazine[i];
        int onceki,sonraki;
        int ind=lower_bound(safe,safe+q,treasure)-safe;
        if(ind==q)
            sonraki=safe[q-1],onceki=safe[q-2];
        else if(ind==0)
            sonraki=safe[0],onceki=safe[0];
        else
            sonraki=safe[ind],onceki=safe[ind-1];

        int sag,sol;
        sol=abs(pos-onceki)+1+abs(treasure-onceki);
        sag=abs(pos-sonraki)+1+abs(treasure-sonraki);
        ans+=min(sag,sol);
        pos=treasure;
    }
    cout<<ans<<"\n";

    return 0;
}