/*
ID: semihca1
TASK: castle
LANG: C++                 
*/
#define isim  "castle"

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,bool> iib; // 1 için N, 0 için E.
// i,j
const int N=55;

int n,m;
bool sagduvar[N][N];
bool ustduvar[N][N];
vector<int> room; // odaların alanları
int roomnumber[N][N]; // Her bir hücre için

void dfs(int i,int j){
    int number=roomnumber[i][j]; // bileşen numarası
    room[number]+=1;
    if(j<m and sagduvar[i][j]==false and roomnumber[i][j+1]==-1){ // sag
        roomnumber[i][j+1]=number;
        dfs(i,j+1);
    }
    if(j>1 and sagduvar[i][j-1]==false and roomnumber[i][j-1]==-1){ // sol
        roomnumber[i][j-1]=number;
        dfs(i,j-1);
    }
    if(i>1 and ustduvar[i][j]==false and roomnumber[i-1][j]==-1){ // yukarı
        roomnumber[i-1][j]=number;
        dfs(i-1,j);
    }
    if(i<n and ustduvar[i+1][j]==false and roomnumber[i+1][j]==-1){ // aşağı
        roomnumber[i+1][j]=number;
        dfs(i+1,j);
    }
}

iib cmp(iib a,iib b){
    if(a.first.first==b.first.first&&a.first.second==b.first.second){
        if(a.second==b.second)
            return a;
        if(a.second==1)
            return a;
        return b;
    }
    if(a.first.second==b.first.second){
        if(a.first.first>b.first.first)
            return a;
        return b;
    }
    if(a.first.second<b.first.second)
        return a;
    return b;
}

int main() {
    // freopen( &*(string(isim)+".in").begin() , "r" , stdin );
    // freopen( &*(string(isim)+".out").begin() , "w" , stdout );
    cin>>m>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            int a;
            cin>>a;
            bool bati=0,kuzey=0,dogu=0,guney=0;
            {  if(a>=8)
                guney=1,a-=8;
            if(a>=4)
                dogu=1,a-=4;
            if(a>=2)
                kuzey=1,a-=2;
            if(a>=1)
                bati=1,a-=1;
            } 
            sagduvar[i][j]=dogu;
            ustduvar[i][j]=kuzey;
        }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            roomnumber[i][j] = -1;
    
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            if(roomnumber[i][j]==-1){
                roomnumber[i][j]=room.size();
                room.push_back(0);
                dfs(i,j);
            }
        }
    cout<<room.size()<<'\n';
    int mx=0;
    for(auto i:room)
        mx=max(mx,i);
    cout<<mx<<'\n';

    iib coor;
    mx=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<m;++j)
            if(sagduvar[i][j]==true and roomnumber[i][j]!=roomnumber[i][j+1]){
                int toplam = room[ roomnumber[i][j] ] + room[ roomnumber[i][j+1] ];
                if(toplam>mx){
                    mx=toplam;
                    coor=iib(ii(i,j),false);
                }
                else if(toplam==mx)
                    coor=cmp(coor,iib(ii(i,j),false));
            }
    for(int i=2;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(ustduvar[i][j]==true and roomnumber[i][j]!=roomnumber[i-1][j]){
                int toplam = room[ roomnumber[i][j] ] + room[ roomnumber[i-1][j] ];
                if(toplam>mx){
                    mx=toplam;
                    coor=iib(ii(i,j),true);
                }
                else if(toplam==mx)
                    coor=cmp(coor,iib(ii(i,j),true));
            }
    char secim=coor.second==1?'N':'E';
    cout<<mx<<'\n'<<coor.first.first<<' '<<coor.first.second<<' '<<secim<<'\n';
}    