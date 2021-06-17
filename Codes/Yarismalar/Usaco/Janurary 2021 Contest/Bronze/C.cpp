#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;

int n;
int a[25],b[25];
int yer[25];

int main(){
    fast;
    freopen("/home/semih/Desktop/Pc Olympic/test/test.in","r",stdin);
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<n;++i)
        cin>>b[i];
    for(int i=0;i<n;++i)
        yer[i]=i;
    int cnt=0;
    do{
        bool flag=true;
        for(int i=0;i<n;++i){
            if(a[i]>b[yer[i]]){
                flag=false;
                break;
            }
        }
        if(flag)
            cnt++;
    }
    while(next_permutation(yer,yer+n));
    cout<<cnt<<endl;
}