#include<semih/competitive.h>

ii a1,a2,b1,b2;

int main(){
    fast;
    test("billboard");
    // test();

    cin>>b1.fi>>b1.se>>b2.fi>>b2.se>>a1.fi>>a1.se>>a2.fi>>a2.se;    
    int n=b2.fi-b1.fi,m=b2.se-b1.se;

    if(b1.fi>=a1.fi and b2.fi<=a2.fi){
        if(b1.se<=a2.se and b1.se>=a1.se and b2.se<=a2.se)
            cout<<0<<"\n";
        else if(b1.se<=a2.se and b1.se>=a1.se)
            cout<<(b2.se-a2.se)*n<<"\n";
        else if(b2.se>=a1.se and b2.se<=a2.se and b1.se>=a1.se)
            cout<<0<<"\n";
        else if(b2.se>=a1.se and b2.se<=a2.se)
            cout<<(a1.se-b1.se)*n<<"\n";
        else
            cout<<n*m<<"\n";
    }
    else if(b1.se>=a1.se and b2.se<=a2.se){
        if(b1.fi<=a2.fi and b1.fi>=a1.fi and b2.fi<=a2.fi)
            cout<<0<<"\n";
        else if(b1.fi<=a2.fi and b1.fi>=a1.fi)
            cout<<(b2.fi-a2.fi)*m<<"\n";
        else if(b2.fi>=a1.fi and b2.fi<=a2.fi and b1.fi>=a1.fi)
            cout<<0<<"\n";
        else if(b2.fi>=a1.fi and b2.fi<=a2.fi)
            cout<<(a1.fi-b1.fi)*n<<"\n";
        else
            cout<<n*m<<"\n";
    }
    else{
        cout<<n*m<<"\n";
    }

    return 0;
}