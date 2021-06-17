#include<bits/stdc++.h>
using namespace std;

int odd,even;

int main(){
    int n;
    int tek=0,cift=0;
    cin>>n;
    for(int i=1;i<=n;++i){
        int a;
        cin>>a;
        if(a%2){ 
            tek++;
            odd=i;
        }
        else{
            cift++;
            even=i;
        }
    }
    if(tek==1)
        cout<<odd;
    else
        cout<<even;
    
    

}