#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

int t;
int n,yilan,el;
int fipos[N];
int engel[10005];
int ilerlemee[N];

int main(){
     freopen("out.txt","w",stdout);
     freopen("in.txt","r",stdin);
    cin>>t;
    while(t--){
        cin>>n>>yilan>>el;
        for(int i=0;i<10000;++i)
            engel[i]=0;
        for(int i=0;i<yilan;++i){
            int a,b;
            cin>>a>>b;
            engel[a]=b;
        }
        for(int i=0;i<el;++i)
            cin>>ilerlemee[i];
        
        for(int i=0;i<n;++i)
            fipos[i]=1;
        
        for(int i=0;i<el;++i){
            int ilerleme=ilerlemee[i];
            int oyuncu=i%n;
            int hedef=fipos[oyuncu]+ilerleme;
            if(hedef<=100 and engel[hedef])
                hedef=engel[hedef];
            if(hedef>=100){
                fipos[oyuncu]=100;
                break;
            }
            fipos[oyuncu]=hedef;
        }
        for(int i=0;i<n;++i)
            cout<<"Position of player "<<i+1<<" is "<<fipos[i]<<".\n";
    }
}
