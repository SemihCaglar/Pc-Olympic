#include<semih/competitive.h>

ii p[105];
map<int,set<int>> x,y;
int n;

int f(set<int> *st,int m){
    return max(m-*st->begin(),*st->rbegin()-m);
}

ll mx=-1;

int main(){
    fast;
    test("triangles");
    // test();

    cin>>n;    
    for(int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;
        x[a].insert(b);
        y[b].insert(a);
        p[i]={a,b};
    }
    for(int i=0;i<n;++i){
        int apsis=p[i].fi,ordinat=p[i].se;
        mx=max( mx, 1LL*f(&x[apsis],ordinat)*f(&y[ordinat],apsis) );
    }

    cout<<mx<<"\n";

    return 0;
}
