#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin>>n,n){
        int x,y;
        cin>>x>>y;
        while(n--){
            int a,b;
            cin>>a>>b;
            if(a==x||b==y)
                cout<<"divisa";
            else if(a<x and b>y)
                cout<<"NO";
            else if(a>x and b>y)
                cout<<"NE";
            else if(a>x and b<y)
                cout<<"SE";
            else
                cout<<"SO";
            cout<<"\n";
        }
    }
}