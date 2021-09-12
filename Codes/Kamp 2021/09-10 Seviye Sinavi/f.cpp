#include<semih/competitive.h>

int y;

bool artik(int x){
    if(x%400==0)
        return true;
    if(x%100==0)
        return false;
    if(x%4==0)
        return true;
    return false;
}

int main(){
    fast;
    // test();
    cin>>y;
    bool leap=artik(y);
    int mod=0;
    while(true){
        mod+=1+artik(y);
        mod%=7;
        y++;
        if(mod==0 and leap==artik(y)){
            cout<<y<<"\n";
            break;
        }
    }        
    return 0;
}