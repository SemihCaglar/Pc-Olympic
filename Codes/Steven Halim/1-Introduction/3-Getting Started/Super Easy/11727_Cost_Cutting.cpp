#include<bits/stdc++.h>
using namespace std;

int cnt;

int main(){
    int t;
    cin>>t;
    while(t--){
        int neblm[3];
        cin>>neblm[0]>>neblm[1]>>neblm[2];
        sort(neblm,neblm+3);
        printf("Case %d: %d\n",++cnt,neblm[1]);
    }
}