#include<semih/competitive.h>

typedef pair<ii,int> route; // 0 yukarı, 1 sağ, 2 aşağı, 3 sola
typedef pair<route,route> cmp;

route farmer,cow;
char ar[15][15];
int n=11;

map<cmp,bool> vis;

bool intable(ii co){
    if(co.fi<=10 and co.fi>=1 and co.se<=10 and co.se>=1 and ar[co.fi][co.se]!='*')
        return true;
    return false;
}

void step(route &x){
    ii &c=x.fi;
    if(x.se==0 and intable(ii(c.fi-1,c.se)) )
        c.fi--;
    else if(x.se==1 and intable(ii(c.fi,c.se+1)) )
        c.se++;
    else if(x.se==2 and intable(ii(c.fi+1,c.se)) )
        c.fi++;
    else if(x.se==3 and intable(ii(c.fi,c.se-1)) )
        c.se--;
    else
        x.se=(x.se+1)%4;
}

void solve(){
    forr(i,1,n)
        forr(j,1,n)
            cin>>ar[i][j];
    forr(i,1,n)
        forr(j,1,n){
            char tmp=ar[i][j];
            if(tmp=='F')
                farmer=route(ii(i,j),0);
            if(tmp=='C')
                cow=route(ii(i,j),0);
        }
    int i=0;
    while(true){
        if(farmer.fi.fi==cow.fi.fi and farmer.fi.se==cow.fi.se)
            break;
        if(vis.count(cmp(farmer,cow))){
            i=1600;
            break;
        }
        vis[cmp(farmer,cow)]=true;
        step(farmer),step(cow);
        i++;
    }
    if(i==1600)
        i=0;
    cout<<i<<endl;

}