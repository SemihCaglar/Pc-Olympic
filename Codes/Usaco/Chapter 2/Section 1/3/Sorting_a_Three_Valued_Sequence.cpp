/*
ID: semihca1
TASK: sort3
LANG: C++                 
*/
#define isim  "sort3"

#include<bits/stdc++.h>
using namespace std;

int n;
int ar[1005];
int cnt[4];
int nothere[4][4];

int main() {
    // freopen( &*(string(isim)+".in").begin() , "r" , stdin );
    // freopen( &*(string(isim)+".out").begin() , "w" , stdout );
    cin>>n;
    for(int i=1;i<=n;++i){
        int a;
        cin>>a;
        cnt[a]++;
        ar[i]=a;
    }
    for(int i=1;i<=cnt[1];++i){
        if(ar[i]!=1)
            nothere[1][ar[i]]++;
    }
    for(int i=1;i<=cnt[2];++i){
        if(ar[i+cnt[1]]!=2)
            nothere[2][ar[i+cnt[1]]]++;
    }
    for(int i=1;i<=cnt[3];++i){
        if(ar[i+cnt[1]+cnt[2]]!=3)
            nothere[3][ar[i+cnt[1]+cnt[2]]]++;
    }
    int result=0;

    int tmp=min(nothere[1][3],nothere[3][1]);
    result+=tmp;
    nothere[1][3]-=tmp;
    nothere[3][1]-=tmp;

    tmp=min(nothere[1][2],nothere[2][1]);
    result+=tmp;
    nothere[1][2]-=tmp;
    nothere[2][1]-=tmp;
    
    tmp=min(nothere[2][3],nothere[3][2]);
    result+=tmp;
    nothere[2][3]-=tmp;
    nothere[3][2]-=tmp;

    tmp=nothere[1][2]+nothere[1][3]+nothere[2][1]+nothere[2][3]+nothere[3][1]+nothere[3][2];
    result+=tmp/3*2;
    
    cout<<result<<endl;
}    