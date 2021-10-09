#include<semih/competitive.h>

int n,m;
vii puanlar;
char a[150][150];

bool comp(ii a,ii b){
    if(a.fi>b.fi)
        return true;
    else if(a.fi<b.fi)
        return false;
    return a.se<b.se;
}

int oyun(char x,char y){ // 1 ise 1. kazandı, 2 ise 2. kazandı, 0 ise berabere
    if(x==y)
        return 0;
    if(x=='G' and y=='C')
        return 1;
    if(x=='C' and y=='P')
        return 1;
    if(x=='P' and y=='G')
        return 1;

    return 2;
}

int main(){
    fast;
    // test();

    cin>>n>>m;

    for(int i=1;i<=2*n;++i)
        for(int j=1;j<=m;++j)
            cin>>a[i][j];

    for(int i=1;i<=2*n;++i)
        puanlar.pb({0,i});    
    
    for(int j=1;j<=m;++j){
        sort(all(puanlar),comp);
        vii tmp;
        for(int i=0;i+1<2*n;i+=2){
            int kazanan=oyun( a[puanlar[i].se][j] , a[puanlar[i+1].se][j] );
            if(kazanan==1){
                tmp.pb( {puanlar[i].fi+1 , puanlar[i].se} );
                tmp.pb( {puanlar[i+1].fi , puanlar[i+1].se} );
            }
            else if(kazanan==2){
                tmp.pb( {puanlar[i].fi , puanlar[i].se} );
                tmp.pb( {puanlar[i+1].fi+1 , puanlar[i+1].se} );
            }
            else{
                tmp.pb( {puanlar[i].fi , puanlar[i].se} );
                tmp.pb( {puanlar[i+1].fi , puanlar[i+1].se} );
            }
                
        }
        puanlar.clear();
        for(auto j:tmp)
            puanlar.pb(j);
        tmp.clear();
    }
    sort(all(puanlar),comp);
    for(auto i:puanlar)
        cout<<i.se<<"\n";

    return 0;
}