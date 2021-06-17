#include<bits/stdc++.h>
using namespace std;
int t,x,y;

int main(){
    cin>>t;
    while(t--){
        cin>>x>>y;
        int sum=0;
        if(x>=y){
            x-=y;
            sum+=y*2;
            sum+=x!=0?2*x-1:0;
        }
        else if(y>=x){
            y-=x;
            sum+=x*2;
            sum+= y!=0 ? 2*y-1 :0;
        }
        cout<<sum<<'\n';
    }    
}