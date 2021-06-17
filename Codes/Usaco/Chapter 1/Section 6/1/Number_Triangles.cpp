/*
ID: semihca1
TASK: numtri
LANG: C++                 
*/
#define isim  "numtri"

#include<bits/stdc++.h>
using namespace std;
int r;
vector<int> rows[1005];
vector<int> pascal[1005];

int main() {
    //freopen( &*(string(isim)+".in").begin() , "r" , stdin );
    //freopen( &*(string(isim)+".out").begin() , "w" , stdout );
    cin>>r;
    for(int i=1;i<=r;++i){
        for(int j=0;j<i;++j){
            int a;
            cin>>a;
            rows[i-1].push_back(a);
        }
    }
    pascal[0].push_back(rows[0][0]);
    #define arti rows[i][j]
    for(int i=1;i<r;++i){
        for(int j=0;j<=i;++j){
            if(j==0){
                pascal[i].push_back(pascal[i-1][0]+arti);
            }
            else if(j==i){
                pascal[i].push_back(pascal[i-1][i-1]+arti);
            }
            else{
                pascal[i].push_back( max(pascal[i-1][j-1],pascal[i-1][j])+arti );
            }
        }
    }
    int mx=0;

    for(int i=0;i<r;++i){
        mx=max(mx,pascal[r-1][i]);
    }
    cout<<mx<<endl;

}    