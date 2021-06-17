/*
ID: semihca1
TASK: transform
LANG: C++                 
*/
#define isim "transform"

#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
typedef pair<int,int> ii;
char bef[20][20];
char aft[20][20];
int n;

int main() {
    ifstream fin (string(".in").insert(0,isim));
    ofstream fout (string(".out").insert(0,isim));
    fin>>n;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            fin>>bef[i][j];
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            fin>>aft[i][j];
    int mini=6;
    bool ok=false;
    for(int i=0;i<2;++i){
        for(int j=0;j<4;++j){
            for(int k=0;k<2;++k){
                for(int m=0;m<4;++m){
                   
                    bool durum=true;
                    for (int a = 0; a < n; ++a)
                        for (int b = 0; b < n; ++b){
                            ii hey = ii(a,b);
                            if(i)
                                hey=ii(hey.first,n-1-hey.second);
                            for (int c = 0; c<j;++c)
                                hey = ii(hey.second, n-1 - hey.first);
                            if(k)
                                hey=ii(hey.first,n-1-hey.second);    
                            for (int c = 0; c<m;++c)
                                hey = ii(hey.second, n-1 - hey.first);
                            
                            if(bef[a][b]!=aft[hey.first][hey.second]){
                                durum=false;
                                goto theschool;
                            }    
                        }
                    theschool:
                    if(durum){
                        ok=true;
                        if(!i&&!j&&!k&&!m)
                            mini=6;
                        else if(!i&&!k&&(j+m)%4!=0)
                            mini=min(mini,(j+m)%4);
                        else if(!j&&!m)
                            mini=min(mini,4);
                        else
                            mini=min(mini,5);        
                    }    
                
                }
            }
        }
    }
    son:
    if(!ok)
        mini=7;
    fout<<mini<<endl;    


}    