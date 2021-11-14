#include<semih/competitive.h>

struct Rect{
    ii p1,p2;
};

Rect x,y,ans;

int main(){
    fast;
    test("square");
    // test();

    cin>>x.p1.fi>>x.p1.se>>x.p2.fi>>x.p2.se;
    cin>>y.p1.fi>>y.p1.se>>y.p2.fi>>y.p2.se;
    
    ans.p1.fi=min(x.p1.fi,y.p1.fi);
    ans.p1.se=min(x.p1.se,y.p1.se);
    ans.p2.fi=max(x.p2.fi,y.p2.fi);
    ans.p2.se=max(x.p2.se,y.p2.se);

    int n=max( ans.p2.fi-ans.p1.fi , ans.p2.se-ans.p1.se );
    cout<<n*n<<"\n";

    return 0;
}