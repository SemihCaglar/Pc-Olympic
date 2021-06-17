/*
ID: semihca1
TASK: holstein
LANG: C++                 
*/
#define isim  "holstein"

#include<bits/stdc++.h>
using namespace std;

int v,g;
int cow[28];
vector<int> feeds[18];

bool choose[18];
int top;
int mn=0x7fffffff;
vector<int> cevap;

bool control(){
    int sonuc[28];
    for(int i=0;i<28;++i)
        sonuc[i]=0;
    for(int i=0;i<g;++i)
        if(choose[i])
            for(int j=0;j<v;++j)
                sonuc[j]+=feeds[i][j];          
    
    for(int i=0;i<v;++i)
        if(sonuc[i]<cow[i])
            return false;
    return true;  
}

void dfs(int n){
    if(control())
        if(top<mn){
            mn=top;
            cevap.clear();
            for(int i=0;i<g;++i)
                if(choose[i])
                    cevap.push_back(i+1);
        }
    if(n==g)
        return;
    choose[n]=true,top++;
    dfs(n+1);
    choose[n]=false,top--;
    dfs(n+1);
}

int main() {
    // freopen( &*(string(isim)+".in").begin() , "r" , stdin );
    // freopen( &*(string(isim)+".out").begin() , "w" , stdout );
    cin>>v;
    for(int i=0;i<v;++i)
        cin>>cow[i];
    cin>>g;
    for(int i=0;i<g;++i)
        for(int j=0;j<v;++j){
            int a;
            cin>>a;
            feeds[i].push_back(a);
        }
    dfs(0);
    cout<<mn;
    for(auto i:cevap)
        cout<<' '<<i;
    cout<<endl;
}    