#include<bits/stdc++.h>
using namespace std;

int n,x;
string s;

int main(){
    cin>>n>>x>>s;
    for(auto i:s){
        if(i=='x'&&x>0)
            x--;
        else if(i=='o')
        {
            x++;
        }
        
    }
    cout<<x;
}