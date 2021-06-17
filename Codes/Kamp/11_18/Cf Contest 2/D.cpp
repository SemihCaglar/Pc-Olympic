#include<bits/stdc++.h>
using namespace std;
const int N=3e4+5;
int n,t;
int a[N];
bool vis[N];

int main(){
    cin>>n>>t;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    int loc=1;
    while(true){
        loc=loc+a[loc];
        if(loc==t){
            cout<<"YES";
            return 0;
        }
        if(vis[loc])
            break;
        vis[loc]=true;
    }
    cout<<"NO";
}