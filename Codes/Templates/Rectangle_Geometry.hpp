typedef struct Point{

    ii p1,p2;
    Point(){

    }
    Point(ii P1,ii P2){
        p1=P1,p2=P2;
    }
    void Get(){
        cin>>p1.fi>>p1.se>>p2.fi>>p2.se;
    }
    ll Area(){
        if(p2.fi<p1.fi or p2.se<p1.se)
            return 0LL;
        return 1LL*(p2.fi-p1.fi)*(p2.se-p1.se);
    }
    Point Intersect(Point x){
        ii nokta1={ max(p1.fi,x.p1.fi) , max(p1.se,x.p1.se) };
        ii nokta2={ min(p2.fi,x.p2.fi) , min(p2.se,x.p2.se) };
        return Point(nokta1,nokta2);
    }
    ll Union(Point x){
        return Area()+x.Area()-Intersect(x).Area();
    } 

}Point;