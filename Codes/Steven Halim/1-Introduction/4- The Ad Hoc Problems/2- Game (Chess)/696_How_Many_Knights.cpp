#include<bits/stdc++.h>
using namespace std;

int n,m;

int main(){
    while(cin>>n>>m,n||m){
        int result;
        if(!n||!m)
            result=0;
        else if(n==1 or m==1)
            result=max(n,m);
        else if(n==2 and m==2)
            result=4;
        else if(n==2)
            result= m%4==1 ? 2*(m/4*2+1) : 2 * 2*((m+3)/4);
        else if(m==2)
            result= n%4==1 ? 2*(n/4*2+1) : 2 * 2*((n+3)/4);
        else
            result= ((n+1)/2) * ((m+1)/2) + (n/2) * (m/2);
        printf("%d knights may be placed on a %d row %d column board.\n",result,n,m);
    }
}