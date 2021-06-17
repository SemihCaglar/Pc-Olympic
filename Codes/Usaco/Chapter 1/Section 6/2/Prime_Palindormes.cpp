/*
ID: semihca1
TASK: pprime
LANG: C++                 
*/
#define isim  "pprime"

#include<bits/stdc++.h>
using namespace std;
int l,r;

bool asal(int x){
    for(int i=2;i*i<=x;++i)
        if(x%i==0)
            return false;
    return true;
}
int number(int a,int b,int c,int d){
    if(a==0&&b==0&&c==0)
        return d;
    if(a==0&&b==0)
        return c*(1e2+1)+d*(1e1);
    if(a==0)
        return b*(1e4+1)+c*(1e3+1e1)+d*(1e2);
    return a*(1e6+1)+b*(1e5+1e1)+c*(1e4+1e2)+d*(1e3);
}

void yazdir(){
    // a b c d c b a
    int a,b,c,d,son=-1;
    for(a=0;a<10;++a){
        if(a>0&&a%2==0)
            continue;

        for(b=0;b<10;++b)
            for(c=0;c<10;++c)
                for(d=0;d<10;++d){
                    int sayi=number(a,b,c,d);
                    if(sayi>r||sayi<l)
                        continue;
                    if(sayi==101&&11>=l&&11<=r)
                        cout<<"\n11";
                    if(asal(sayi)){
                        if(son!=-1)
                            cout<<'\n';
                        cout<<sayi;
                        son=sayi;
                    }
                }
    }
    if(son==7&&11>=l&&11<=r)
        cout<<"\n11";
}

int main() {
    //freopen( &*(string(isim)+".in").begin() , "r" , stdin );
    //freopen( &*(string(isim)+".out").begin() , "w" , stdout );
    cin>>l>>r;
    yazdir();
    cout<<endl;
}    