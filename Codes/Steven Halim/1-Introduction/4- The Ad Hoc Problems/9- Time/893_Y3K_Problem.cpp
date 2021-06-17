#include<bits/stdc++.h>
using namespace std;

int n,gun,ay,yil;
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
    if (gun > ar[ay])
    {
        gun -= ar[ay];
        artiray();
    }
}
void artiray(){
    (ay==12) ? ay=0,yil++ : ay++;
    yuvarla();
}

int main(){
    while(cin>>n>>gun>>ay>>yil,n or gun or ay or yil){
        while(n){
            if(n>=365+leap(yil)){
                n-=365+ ( (ay<=2)?leap(yil):leap(yil+1) );
                yil++;
                yuvarla();
            }
            else{
                if(ay==2)
                    ar[2]=28+leap(yil);
                if(n>=ar[ay]){
                    n-=ar[ay];
                    artiray();
                }
                else{
                    if(ay==2)
                        ar[2]=28+leap(yil);
                    int hedef=gun+n;
                    if(hedef>ar[ay]){
                        gun=hedef-ar[ay];
                        artiray();
                    }
                    else{
                        gun=hedef;
                        yuvarla();
                    }
                    n=0;
                }
            }
            
            // else{
            //     gun+=n;
            //     yuvarla();
            //     break;
            // }

        }
        yuvarla();
        cout<<gun<<" "<<ay<<" "<<yil<<"\n";
    }
}