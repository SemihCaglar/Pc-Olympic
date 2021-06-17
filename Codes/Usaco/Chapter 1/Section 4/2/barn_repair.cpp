/*
ID: semihca1
TASK: barn1
LANG: C++                 
*/
#define isim  "barn1"

// Burda Radix sort kullandım, O(n).
#include<bits/stdc++.h>
using namespace std;

const int N=205;
bool cow[N];
int m,s,c;

int main() {
    freopen( &*(string(isim)+".in").begin() , "r" , stdin );
    freopen( &*(string(isim)+".out").begin() , "w" , stdout );
    cin>>m>>s>>c;
    for(int i=0;i<c;++i){
        int a;
        cin>>a;
        cow[a]=true;
    }
    int bosluk[s+5];
    for(int i=0;i<s+5;++i)
        bosluk[i]=0;
    int cur;
    bool hey=true;
    int bas,son,cnt=0;
    for(bas=1;cow[bas]!=true&&bas<=s;++bas,++cnt);
    for(son=s;cow[son]!=true&&son>=1;--son,++cnt);

    for(int i=bas;i<=son;++i){
        if(hey&&!cow[i]){
            cur=i;
            hey=false;
        }
        else if(!hey&&cow[i]){
            bosluk[i-cur]++;
            hey=true;
        }
    }
    if(!hey)
        bosluk[s+1-cur]++;
    
    m--;
    for(int i=s;i>=1;--i){
        while(bosluk[i]&&m){
            cnt+=i;
            m--;
            bosluk[i]--;
        }
        if(!m)
            break;
    }
    cout<<s-cnt<<"\n";

}    