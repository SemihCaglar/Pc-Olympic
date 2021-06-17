/*
ID: semihca1
TASK: dualpal
LANG: C++                 
*/
#define isim "dualpal"

#include<iostream>
#include<fstream>
using namespace std;
int b;
string convert(int a,int b){
    string s="";
    int i=1,cnt=1;
    for(;i*b<=a;i*=b,++cnt);
    while(cnt--){
        if(a>=i){
            int tmp=a/i;
            char rakam;
            rakam='0'+tmp;
            s+=rakam;
            a-=tmp*i;
        }
        else
            s+='0';
        i/=b;
    }
    return s;
}

bool check(string s){
    for(int i=0;i<s.length()/2;++i)
        if(s[i]!=s[s.length()-1-i])
            return false;
    return true;
}

int main() {
    ifstream fin ((string)isim+".in");
    ofstream fout ((string)isim+".out");
    int n,s;
    fin>>n>>s;
    for(int i=s+1;n;++i){
        int kalan=2;
        bool yo=false;
        for(int j=2;j<=10;++j){
            if(check(convert(i,j)))
                kalan--;
            if(!kalan){
                yo=true;
                break;
            }    
        }
        if(yo){
            fout<<i<<endl;
            n--;
        }
    }
}    