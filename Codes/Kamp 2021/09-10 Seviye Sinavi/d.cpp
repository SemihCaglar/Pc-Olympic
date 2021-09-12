#include<semih/competitive.h>

int n;
string s;
int a,b;

int main(){
    fast;
    // test();

    cin>>n>>s;
    for(auto i:s){
        if(i=='8')
            a++;
        else
            b++;
    }   
    cout<<min(a,(a+b)/11);

    return 0;
}