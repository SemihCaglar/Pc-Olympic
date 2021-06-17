/*
ID: semihca1
TASK: combo
LANG: C++                 
*/
#define isim  "combo"

#include<bits/stdc++.h>
using namespace std;

int combo[2][3];
int n;

bool f(int a,int b){
    int fark=abs(a-b);
    if(fark<=2)
        return true;
    if(n-fark<=2)
        return true;
    return false;
}

int main() {
    //freopen( &*(string(isim)+".in").begin() , "r" , stdin );
    //freopen( &*(string(isim)+".out").begin() , "w" , stdout );
    cin>>n;
    int a,b,c;
    cin>>a>>b>>c;
    int num=1;
    combo[0][0]=a,combo[0][1]=b,combo[0][2]=c;
    cin>>a>>b>>c;
    if(a==combo[0][0]&&b==combo[0][1]&&c==combo[0][2]){}
    else{
        combo[1][0]=a,combo[1][1]=b,combo[1][2]=c;
        num=2;
    }
    int cnt=0;
    #define fori(i) for(int i=1;i<=n;++i)
    fori(i)
        fori(j)
            fori(k){
                if(f(i,combo[0][0])&&f(j,combo[0][1])&&f(k,combo[0][2]))
                    cnt++;
                else if(num==2&&f(i,combo[1][0])&&f(j,combo[1][1])&&f(k,combo[1][2]))
                    cnt++;
            }
    cout<<cnt<<endl;

} 