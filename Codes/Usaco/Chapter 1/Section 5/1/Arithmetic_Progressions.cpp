/*
ID: semihca1
TASK: ariprog
LANG: C++                 
*/
#define isim  "ariprog"

#include<bits/stdc++.h>
using namespace std;
const int N=2*250*250+5;
bool bisquare[N];
vector<int> sayilar;
int n,m;
bool ciddi=false;
int main() {
    //freopen( &*(string(isim)+".in").begin() , "r" , stdin );
    //freopen( &*(string(isim)+".out").begin() , "w" , stdout );
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int p=0;p<=m;++p)
        for(int q=0;q<=m;++q){
            if(bisquare[p*p+q*q]==false){
            bisquare[p*p+q*q]=true;
            sayilar.push_back(p*p+q*q);
            }
        }
    // a,a+b,a+2b,a+nb
    sort(sayilar.begin(),sayilar.end());
    int a=-1,b=0;
    while(++b,true){
        if(b*(n-1)+0>2*m*m+4)
            break;
        
        a=-1;
        for(auto a:sayilar){
            if(b*(n-1)+a>2*m*m+4)
                break;

            bool neblm=false;
            for(int i=1;i<=n;++i){
                int sayi=b*(i-1)+a;
                if(bisquare[sayi]==false){
                    neblm=true;
                    break;
                }
            }
            if(neblm==true)
                continue;
            else{
                ciddi=true;
                cout<<a<<' '<<b<<endl;   
            }
        }
        
    }
    if(ciddi==false)
        cout<<"NONE\n";
    
}    