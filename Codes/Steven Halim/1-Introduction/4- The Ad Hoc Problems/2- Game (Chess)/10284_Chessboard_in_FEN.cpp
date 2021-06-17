#include<bits/stdc++.h>
using namespace std;

string s;
char chess[8][8];
bool vis[8][8];

bool sag(int i,int j){
    if(j>7)
        return false;
    return true;
}
bool sol(int i,int j){
    if(j<0)
        return false;
    return true;
}
bool asagi(int i,int j){
    if(i>7)
        return false;
    return true;
}
bool yukari(int i,int j){
    if(i<0)
        return false;
    return true;
}

void capraz(int i,int j){
    bool sagyukari,solyukari,sagasagi,solasagi;
    sagyukari=solyukari=sagasagi=solasagi=true;

    for(int a=1;a<=8;++a){
        if(sag(i+a,j+a) and asagi(i+a,j+a) and sagasagi){
            if(chess[i+a][j+a])
                sagasagi=false;
            vis[i+a][j+a]=true;
        }
        if(sol(i+a,j-a) and asagi(i+a,j-a) and solasagi){
            if(chess[i+a][j-a])
                solasagi=false;
            vis[i+a][j-a]=true;
        }
        if(sag(i-a,j+a) and yukari(i-a,j+a) and sagyukari){
            if(chess[i-a][j+a])
                sagyukari=false;
            vis[i-a][j+a]=true;
        }
        if(sol(i-a,j-a) and yukari(i-a,j-a) and solyukari){
            if(chess[i-a][j-a])
                solyukari=false;
            vis[i-a][j-a]=true;
        }
    }
}
void yataydikey(int i,int j){
    bool fsag,fasagi,fsol,fyukari;
    fsag=fsol=fasagi=fyukari=true;
    for(int a=1;a<=8;++a){
        if(sag(i,j+a) and fsag){
            if(chess[i][j+a])
                fsag=false;
            vis[i][j+a]=true;
        }
        if(sol(i,j-a) and fsol){
            if(chess[i][j-a])
                fsol=false;
            vis[i][j-a]=true;
        }
        if(asagi(i+a,j) and fasagi){
            if(chess[i+a][j])
                fasagi=false;
            vis[i+a][j]=true;
        }        
        if(yukari(i-a,j) and fyukari){
            if(chess[i-a][j])
                fyukari=false;
            vis[i-a][j]=true;
        }
    }
}

void sah(int i,int j){
    if(sag(i+1,j+1) and asagi(i+1,j+1))
        vis[i+1][j+1]=true;
    if(sol(i+1,j-1) and asagi(i+1,j-1))
        vis[i+1][j-1]=true;
    if(sag(i-1,j+1) and yukari(i-1,j+1))
        vis[i-1][j+1]=true;        
    if(sol(i-1,j-1) and yukari(i-1,j-1))
        vis[i-1][j-1]=true;
    
    if(sag(i,j+1))
        vis[i][j+1]=true;
    if(sol(i,j-1))
        vis[i][j-1]=true;
    if(asagi(i+1,j))
        vis[i+1][j]=true;        
    if(yukari(i-1,j))
        vis[i-1][j]=true;
}
void kale(int i,int j){
    yataydikey(i,j);
}
void vezir(int i,int j){
    yataydikey(i,j);
    capraz(i,j);
}
void siyahpiyon(int i,int j){
    if(sag(i+1,j+1) and asagi(i+1,j+1))
        vis[i+1][j+1]=true;
    if(sol(i+1,j-1) and asagi(i+1,j-1))
        vis[i+1][j-1]=true;    
}
void beyazpiyon(int i,int j){
    if(sag(i-1,j+1) and yukari(i-1,j+1))
        vis[i-1][j+1]=true;        
    if(sol(i-1,j-1) and yukari(i-1,j-1))
        vis[i-1][j-1]=true;
}
void fil(int i,int j){
    capraz(i,j);
}
void at(int i,int j){
    for(int one=0;one<2;one++)
        for(int two=0;two<2;two++){
            int carpan1=one?1:-1;
            int carpan2=two?1:-1;
            if( sol(i+(1*carpan1),j+(2*carpan2)) and sag(i+(1*carpan1),j+(2*carpan2)) and yukari(i+(1*carpan1),j+(2*carpan2)) and asagi(i+(1*carpan1),j+(2*carpan2)))
                vis[i+(1*carpan1)][j+(2*carpan2)]=true;
            if( sol(i+(2*carpan1),j+(1*carpan2)) and sag(i+(2*carpan1),j+(1*carpan2)) and yukari(i+(2*carpan1),j+(1*carpan2)) and asagi(i+(2*carpan1),j+(1*carpan2)))
                vis[i+(2*carpan1)][j+(1*carpan2)]=true;
        }
}

int main(){

    while(cin>>s){
        memset(chess,0,sizeof(chess));
        memset(vis,0,sizeof(vis));
        
        int col=0,row=0;
        for(int i=0;i<s.length();++i,++row){
            if(s[i]<='9'&&s[i]>='0'){
                    for(int n=s[i]-'0'+row;row<n;++row)
                        chess[col][row]=0;
                    --row;
            }
            else if(s[i]=='/')
                col++,row=-1;
            else
                chess[col][row]=s[i];   
        }

        for(int i=0;i<8;++i)
            for(int j=0;j<8;++j){
                bool flag=false;
                switch(chess[i][j]){
                    case 'p': siyahpiyon(i,j); flag=true; break;
                    case 'P': beyazpiyon(i,j); flag=true; break;
                    case 'n': case 'N': at(i,j); flag=true; break;
                    case 'b': case 'B': fil(i,j); flag=true; break;
                    case 'r': case 'R': kale(i,j); flag=true; break;
                    case 'q': case 'Q': vezir(i,j); flag=true; break;
                    case 'k': case 'K': sah(i,j); flag=true; break;
                }
                if(flag)    
                    vis[i][j]=true;
            }
        int cnt=0;
        for(int i=0;i<8;++i)
            for(int j=0;j<8;++j)
                if(vis[i][j]==false)
                    cnt++;       
        cout<<cnt<<'\n';
    }

}