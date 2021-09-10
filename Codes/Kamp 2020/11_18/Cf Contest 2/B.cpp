#include<bits/stdc++.h>
using namespace std;

int main(){
    int x;
    int step=0;
    cin>>x;
    while(x>=5){
        x-=5,step++;
    }
    while(x>=4){
        x-=4,step++;
    }
    while(x>=3){
        x-=3,step++;
    }
    while(x>=2){
        x-=2,step++;
    }
    while(x>=1){
        x-=1,step++;
    }
    cout<<step;
}