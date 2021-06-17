/*
ID: semihca1
TASK: friday
LANG: C++                 
*/
#include <iostream>
#include <fstream>
using namespace std;
int n;
int week[10];

bool leap(int n){
    if(n%100==0){
        if(n%400==0)
            return true;
        else
            return false; 
    }
    if(n%4==0)
        return true;
    return false;    
}

int main() {
    const string isim="friday";
    ofstream fout (string(".out").insert(0,isim));
    ifstream fin (string(".in").insert(0,isim));

    fin>>n;
    int day=6;
    for(int i=1900;i<1900+n;++i){
        for(int j=1;j<=12;++j){
            ++week[day];
            if(j==2){
                if(leap(i)){
                    day=(day+29)%7;
                }
                else
                    day=(day+28)%7;
            }
            else if(j==4||j==6||j==9||j==11){
                day=(day+30)%7;
            }
            else{
                day=(day+31)%7;
            }
        }
    }
    fout<<week[6]<<' ';
    for(int i=0;i<5;++i){
        fout<<week[i]<<' ';
    }
    fout<<week[5]<<endl;
    return 0;
}    