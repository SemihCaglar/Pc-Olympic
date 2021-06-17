/*
ID: semihca1
TASK: beads
LANG: C++                 
*/
#include <iostream>
#include <fstream>
using namespace std;

int n;
string boncuk;

void artir(int &x,int c,bool op){
    if(op)
        x= c==boncuk.length()-1?-1:x==boncuk.length()-1?0:x+1;
    else
        x= c==boncuk.length()-1?-1:x==0?boncuk.length()-1:x-1;
}

int find(int yer,bool op){
    bool durum=true;
    int renk=-1;
    int cnt=0;
    int c=0;
    for(int i=yer;durum&&i!=-1;artir(i,c,op),++c){
        switch(boncuk[i]){
            case 'w': ++cnt; break;
            case 'r':
                if(renk==-1){
                    renk=1;
                    ++cnt;
                }
                else if(renk==1)
                    ++cnt;
                else
                    durum=false;
                break;
            case 'b':
                if(renk==-1){
                    renk=0;
                    ++cnt;
                }
                else if(renk==0)
                    ++cnt;
                else
                    durum=false;
                break;
        }
    }
    return cnt;
}

int main() {
    const string isim="beads";
    ifstream fin (string(".in").insert(0,isim));
    ofstream fout (string(".out").insert(0,isim));
    fin>>n;
    fin>>boncuk;

    int max=0;
    for(int i=0;i<n-1;++i){
        int temp=0;
        temp+=find(i+1,1);
        if(temp!=boncuk.length())
            temp+=find(i,0);
        if(temp>max)
            max=temp;
    }
    fout<<max<<endl;

}    