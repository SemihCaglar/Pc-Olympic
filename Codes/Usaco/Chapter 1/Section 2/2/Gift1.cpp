/*
ID: semihca1
TASK: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
using namespace std;

int NP;
string name[15];
int answ[15];

int find(string s){
    for(int i=0;i<NP;++i)
        if(s==name[i])
            return i;
}

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    fin>>NP;
    for(int i=0;i<NP;++i){
        fin>>name[i];
    }
    for(int i=0;i<NP;++i){
        int index;
        string a;
        fin>>a;
        index=find(a);
        int b,c,pay;
        fin>>b>>c;
        if(c){
            pay=b/c;
            answ[index]+=b%c;
            answ[index]-=b;
        }
        
        for(int j=0;j<c;++j){
            string s;
            fin>>s;
            int in=find(s);
            answ[in]+=pay;
        }
    }
    for(int i=0;i<NP;++i){
        fout<<name[i]<<' '<<answ[i]<<endl;
    }
    
}    