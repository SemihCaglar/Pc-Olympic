#include<bits/stdc++.h>
using namespace std;

long long a,b,c,d;
int sum;

int main(){
    cin>>a>>b>>c>>d;
    long long x=abs(c-a),y=abs(d-b);
    if(a==c&&b==d){
        cout<<0;
        return 0;
    }
    if(a==c&&abs(d-b)<=6 || d==b&&abs(a-c)<=6){
        cout<<2;
        return 0;
    }
    if(a==c&&abs(d-b)<=6 || d==b&&abs(a-c)<=6){
        cout<<2;
        return 0;
    }    
    switch(abs(x-y)){
        case 0: sum=1; break;
        case 1: sum=2; break;
        default: if(abs(x-y)<=3) sum=2; else sum=2+(abs(x-y)%2);
    }
    cout<<sum;
}