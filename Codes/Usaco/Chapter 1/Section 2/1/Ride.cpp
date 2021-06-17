/*
ID: semihca1
TASK: ride
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a,b;
    fin>>a>>b;
    int mod1=1,mod2=1;
    for(int i=0;i<a.length();++i)
        mod1=mod1*(a[i]-'A'+1)%47;
    for(int i=0;i<b.length();++i)
        mod2=mod2*(b[i]-'A'+1)%47;
    if(mod1==mod2)
        fout<<"GO"<<endl;
    else
        fout<<"STAY"<<endl;
   
    return 0;
}