/*
ID: semihca1
TASK: skidesign
LANG: C++                 
*/
#define isim  "skidesign"

#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> amount;

int f(int a,int b,int c){
    if(a<=c&&c<=b)
        return 0;
    if(a<=c)
        return (c-b)*(c-b);
    return (c-a)*(c-a);
}

int main() {
    //freopen( &*(string(isim)+".in").begin() , "r" , stdin );
    //freopen( &*(string(isim)+".out").begin() , "w" , stdout );
    cin>>n;
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        amount.push_back(a);
    }
    int minimum=0x7fffffff;
    int bas,son;
    for(int bas=1,son=18;son<=100;++bas,++son){
        int tmp=0;
        for(auto i:amount){
            tmp+=f(bas,son,i);
        }
        minimum=min(minimum,tmp);
    }
    cout<<minimum<<endl;
} 