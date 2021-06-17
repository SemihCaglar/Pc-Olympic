/*
ID: semihca1
TASK: namenum
LANG: C++                 
*/
#define isim "namenum"

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

string n;
int cnt=0;
vector<string> acceptable;

int num(char a){
    if(a=='A'||a=='B'||a=='C')
        return 2;
    if(a=='D'||a=='E'||a=='F')
        return 3;    
    if(a=='G'||a=='H'||a=='I')
        return 4;
    if(a=='J'||a=='K'||a=='L')
        return 5;
    if(a=='M'||a=='N'||a=='O')
        return 6;
    if(a=='P'||a=='R'||a=='S')
        return 7;
    if(a=='T'||a=='U'||a=='V')
        return 8;
    if(a=='W'||a=='X'||a=='Y')
        return 9;
}

int main() {
    ifstream fin (string(".in").insert(0,isim));
    ofstream fout (string(".out").insert(0,isim));
    ifstream valid("dict.txt");
    string tmp;
    while(valid>>tmp)
        acceptable.push_back(tmp);
    
    fin>>n;
    for(int i=0;i<acceptable.size();++i){

        if(acceptable[i].length()==n.length()){
            bool durum=true;
            for(int j=0;j<n.length();++j){
                if( num(acceptable[i][j])!=n[j]-'0' ){
                    durum=false;
                    break;
                }    
            }
            if(durum){
                fout<<acceptable[i]<<endl;
                ++cnt;    
            }

        }

    }
    if(!cnt)
        fout<<"NONE"<<endl;
    
}    