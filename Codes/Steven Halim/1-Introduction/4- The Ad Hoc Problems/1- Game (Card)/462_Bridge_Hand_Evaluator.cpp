#include<bits/stdc++.h>
using namespace std;
map<char,int> mp= {{'A',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9},{'T',10},{'J',11},{'Q',12},{'K',13}};
map<char,int> mp2={{'S',1},{'H',2},{'D',3},{'C',4}};

bool a[6][15];
int cont[6];

int bir(){
    int as = 0, k = 0, q = 0, j = 0;
    for (int i = 1; i <= 4; ++i)
    {
        as += a[i][1];
        k += a[i][13];
        q += a[i][12];
        j += a[i][11];
    }
    return 4 * as + 3 * k + 2 * q + 1 * j;
}

int ikidort(){
    int retu=0;
    for(int i=1;i<=4;++i){
        int toplam=0;
        for(int j=1;j<=13;++j)
            if(a[i][j])
                toplam++;
        cont[i]=toplam;
        if(a[i][13] and toplam-1<=0)
            retu++;
        if(a[i][12] and toplam-1<=1)
            retu++;
        if(a[i][11] and toplam-1<=2)
            retu++;
    }
    return retu;
}

int besyedi(){
    int retu=0;
    for(int i=1;i<=4;++i){
        if(cont[i]<=1)
            retu+=2;
        else if(cont[i]==2)
            retu+=1;
    }
    return retu;
}

bool stopped(int i){
    if(a[i][1] or a[i][13] and cont[i]-1>=1 or a[i][12] and cont[i]-1>=2)
        return true;
    return false;
}

int main(){
    char sayi,renk;
    
    while(cin>>sayi>>renk){
        memset(a,0,sizeof(a));
        a[mp2[renk]][mp[sayi]]=true;

        for(int i=1;i<13;++i){
            cin>>sayi>>renk;
            a[mp2[renk]][mp[sayi]]=true;
        }
        int fir,sec;
        fir=bir()-ikidort();
        sec=besyedi();
        if(fir+sec<14){
            cout<<"PASS\n";
        }
        else if(stopped(1) and stopped(2) and stopped(3) and stopped(4) and fir>=16){
            cout<<"BID NO-TRUMP\n";
        }
        #define maxx(a,b,c) max(cont[a],max(cont[b],cont[c]))
        else if(cont[1]>=maxx(2,3,4))
            cout<<"BID S\n";
        else if(cont[2]>=maxx(1,3,4))
            cout<<"BID H\n";
        else if(cont[3]>=maxx(1,2,4))
            cout<<"BID D\n";
        else
            cout<<"BID C\n";
    }
}