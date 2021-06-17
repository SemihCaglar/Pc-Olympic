/*
ID: semihca1
TASK: milk2
LANG: C++                 
*/
#define isim "milk2"

#include <iostream>
#include <fstream>
#include<algorithm>
using namespace std;
typedef pair<int,int> ii;
int n;
ii cows[5100];
bool met(ii a,ii b){
    return a.first<b.first;
}
int main() {
    ifstream fin (string(".in").insert(0,isim));
    ofstream fout (string(".out").insert(0,isim));
    fin>>n;
    for(int i=0;i<n;++i){
        int a,b;
        fin>>a>>b;
        cows[i]=ii(a,b);
    }
    sort(cows,cows+n,met);
    int max1=0,max2=0;
    int cur=cows[0].first;
    int bitis=cows[0].second; 
    for(int i=1;i<n;++i){
        bitis=max(bitis,cows[i-1].second);
        if(cows[i].first>bitis){
            max1=max(max1,bitis-cur);
            cur=cows[i].first;
            max2=max(max2,cows[i].first-bitis);
        }
    }
    bitis=max(bitis,cows[n-1].second);
    max1=max(max1,bitis-cur);

    fout<<max1<<' '<<max2<<endl;

}    