#include<bits/stdc++.h>
using namespace std;

int tmp,gun,ay,yil;
int t,cnt;
int ar[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap(int x){
    if(x%400==0)
        return true;
    if(x%100==0)
        return false;
    if(x%4==0)
        return true;
    return false;
}

void artiray();

void yuvarla(){
    if(ay==2)
        ar[2]=28+leap(yil);
    if(gun>ar[ay]){
        gun-=ar[ay];
        artiray();
    }
}
void artiray(){
    if(ay==12)
        ay=1,yil++;
    else
        ay++;
    yuvarla();
}

int main(){
    cin>>t;
    while(t--){
        scanf("%1d%1d",&tmp,&ay);
        ay=tmp*10+ay;
        scanf("%1d%1d",&tmp,&gun);
        gun=tmp*10+gun;
        yil=0;
        for(int i=0;i<4;++i){
            scanf("%1d",&tmp);
            yil=yil*10+tmp;
        }
        gun+=280;
        yuvarla();
        
        cout<<++cnt<<" ";
        if(ay/10==0)
            cout<<0;
        cout<<ay<<"/";
        if(gun/10==0)
            cout<<0;
        cout<<gun<<"/";
        if(yil/1000==0)
            cout<<0;
        if(yil/100==0)
            cout<<0;
        if(yil/10==0)
            cout<<0;
        cout<<yil<<" ";
        
        #define aralik(x,a,y,b) (ay==x and gun>=a) or (ay==y and gun<=b)
        string res;
        if(aralik(1,21,2,19)) res="aquarius";
        else if(aralik(2,20,3,20)) res="pisces";
        else if(aralik(3,21,4,20)) res="aries";
        else if(aralik(4,21,5,21)) res="taurus";
        else if(aralik(5,22,6,21)) res="gemini";
        else if(aralik(6,22,7,22)) res="cancer";
        else if(aralik(7,23,8,21)) res="leo";
        else if(aralik(8,22,9,23)) res="virgo";
        else if(aralik(9,24,10,23)) res="libra";
        else if(aralik(10,24,11,22)) res="scorpio";
        else if(aralik(11,23,12,22)) res="sagittarius";
        else res="capricorn";

        cout<<res<<'\n';

    }
}