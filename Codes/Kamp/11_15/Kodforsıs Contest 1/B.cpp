#include<bits/stdc++.h>
using namespace std;
int t;
int n,m;
int a[15][15];
int main(){
    
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j)
                cin>>a[i][j];
        }
            
        int eksisayisi = 0,toplam=0;
        for(int i=0;i<n;++i)
                for(int j=0;j<m;++j){
                    if(a[i][j] < 0)
                        ++eksisayisi;
                    toplam+=abs(a[i][j]);
                } 
    
        if(eksisayisi%2==0)
            cout<<toplam;

        else{
            int mn=0x7fffffff;
            for(int i=0;i<n;++i)
                for(int j=0;j<m;++j){
                    mn= min (mn,abs(a[i][j]));
                } 
            cout<<toplam-mn-mn;
        }
        cout<<'\n';
    } 
    return 0;
}







