// https://codeforces.com/contest/1388/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        if(n==36||n==40||n==44){
            printf("YES\n%d %d %d %d\n",6,10,15,n-31);
            continue;
        }
        if(n>30){
            printf("YES\n%d %d %d %d\n",6,10,14,n-30);
            continue;
        }
            //trojan
        else{
            printf("NO\n");
        }

    }
}