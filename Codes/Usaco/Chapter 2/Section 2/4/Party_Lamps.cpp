/*
ID: semihca1
TASK: lamps
LANG: C++                 
*/
#define isim  "lamps"

#include<bits/stdc++.h>
using namespace std;
const int N=105;

int n,c;
int on[N];

bool vis[N];
vector<string> ans;
string s;

void but1(){
    for(int i=0;i<n;++i)
        vis[i]=1-vis[i];
}
void but2(){
    for(int i=0;i<n;i+=2)
        vis[i]=1-vis[i];
}
void but3(){
    for(int i=1;i<n;i+=2)
        vis[i]=1-vis[i];
}
void but4(){
    for(int i=0;i<n;i+=3)
        vis[i]=1-vis[i];
}

bool check(){
    s="";
    for(int i=0;i<n;++i){
        if(on[i]!=-1 and on[i]!=vis[i])
            return false;
        s+=vis[i]+'0';
    }
    return true;
}

int main(){
    // freopen( &*(string(isim)+".in").begin() , "r" , stdin );
    // freopen( &*(string(isim)+".out").begin() , "w" , stdout );
    cin>>n>>c;
    memset(on,-1,sizeof(on));

    int tmp;
    while(cin>>tmp,tmp!=-1)
        on[tmp-1]=true;
    while(cin>>tmp,tmp!=-1)
        on[tmp-1]=false;
    
    for(int i=0;i<2;++i)
        for(int j=0;j<2;++j)
            for(int k=0;k<2;++k)
                for(int m=0;m<2;++m){
                    for(int a=0;a<n;++a)
                        vis[a]=true;
                    if(i) but1();
                    if(j) but2();
                    if(k) but3();
                    if(m) but4();
                    if(check()==true and (c-i-j-k-m)%2==0 and (i+j+k+m)<=c){
                        ans.push_back(s);  
                }
    sort(ans.begin(),ans.end());
    for(auto i:ans)
        cout<<i<<'\n';
    if(ans.empty())
        cout<<"IMPOSSIBLE\n";
    return 0;
}