#include<semih/competitive.h>

int t;
int W,H,w,h;
ii x,y;
int ans=INT_MAX;

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){
        cin>>W>>H;
        int a,b;
        cin>>a>>b;
        x=ii(a,b);
        cin>>a>>b;
        y=ii(a,b);

        cin>>w>>h;

        ans=INT_MAX;
        int w2=y.fi-x.fi;
        int h2=y.se-x.se;

        if(h+h2<=H){
            int oluru=h<=x.se?0:h-x.se;
            ans=min(ans,oluru);
            oluru=y.se<=H-h?0:y.se-(H-h);
            ans=min(ans,oluru);
        }
        if(w+w2<=W){
            int oluru=w<=x.fi?0:w-x.fi;
            ans=min(ans,oluru);
            oluru=y.fi<=W-w?0:y.fi-(W-w);
            ans=min(ans,oluru);
        }
        if(ans==INT_MAX)
            cout<<-1<<"\n";
        else
            cout<<ans<<"\n";
    }    

    return 0;
}