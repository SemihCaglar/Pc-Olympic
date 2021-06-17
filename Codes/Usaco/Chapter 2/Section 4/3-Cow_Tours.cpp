#include<semih/competitive.h>
const int N=155;

int n;
ii coordinate[N];
vi v[N];

vector<vi> groups;
int gnumber[N];

double asp[N][N]; // (All Shortest Path)
double enuzak[N]; // her düğümün en uzak olduğu düğüme olan uzaklığı
vector<double> diametre;

void dfs(int x){
    groups[groups.size()-1].pb(x);
    gnumber[x]=groups.size()-1;
    for(int i=0;i<v[x].size();++i){
        int hedef=v[x][i];
        if(gnumber[hedef]==-1)
            dfs(hedef);
    }
}

double f(ii x,ii y){
    int dikey,yatay;
    dikey=abs(x.fi-y.fi);
    yatay=abs(x.se-y.se);
    return hypot(dikey,yatay);
}

void aspHesapla(){
    memset(asp,-1,sizeof(asp));
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            asp[i][j]=-1;
    for(int i=0;i<n;++i){
        
        bool vis[N]={};
        typedef pair<double,int> di;
        priority_queue<di> pq; // (-dist,vertex)
        asp[i][i]=0;
        pq.push(di(0,i));
        while(!pq.empty()){
            di tmp=pq.top();
            pq.pop();
            double dist=tmp.fi*-1;
            int ver=tmp.se;
            if(vis[ver])
                continue;

            for(int j=0;j<v[ver].size();++j){
                int hedef=v[ver][j];
                double belki=dist+f(coordinate[ver],coordinate[hedef]);
                if(asp[i][hedef]==-1 or belki<asp[i][hedef]){
                    asp[i][hedef]=belki;
                    pq.push(di(belki*-1,hedef));
                }
            }
            vis[ver]=true;
        }

    }
}

void enuzakhesapla(){
    for(int i=0;i<n;++i){

        double mx=-5;
        vi &adj=groups[gnumber[i]];
        for(int j=0;j<adj.size();++j){
            int hedef=adj[j];
            mx=max(mx,asp[i][hedef]);
        }
        enuzak[i]=mx;

    }
}

void diametrehesapla(){
    diametre.resize(groups.size());
    for(int i=0;i<groups.size();++i){

        double mx=-5;
        vi &adj=groups[i];
        for(int j=0;j<adj.size();++j){
            int hedef=adj[j];
            mx=max(mx,enuzak[hedef]);
        }
        diametre[i]=mx;

    }
}

double concat(int first,int second){
    double mn=1e9;
    vi &a=groups[first],&b=groups[second];
    
    for(auto i:a)
        for(auto j:b){
            double belki=max( max(diametre[first],diametre[second]) , enuzak[i]+enuzak[j]+f(coordinate[i],coordinate[j]) );
            mn=min(mn,belki);
        }
    
    return mn; 
}

void solve(){
    cin>>n;
    forr(i,0,n){
        int a,b;
        cin>>a>>b;
        coordinate[i]=ii(a,b);
    }
    forr(i,0,n)
        forr(j,0,n){
            char a;
            cin>>a;
            if(a-'0'){
                v[i].pb(j);
                v[j].pb(i);
            }
        }
    
    memset(gnumber,-1,sizeof(gnumber));
    for(int i=0;i<n;++i){
        if(gnumber[i]==-1){
            vi tmp;
            groups.pb(tmp);
            dfs(i);
        }
    }
    aspHesapla();
    enuzakhesapla();
    diametrehesapla();

    double mn=1e9;

    for(int i=0;i<groups.size();++i)
        for(int j=0;j<groups.size();++j){
            if(i==j)
                continue;
            double belki=concat(i,j);
            mn=min(mn,belki);
        }
    printf("%.6lf\n",mn);
    
    
    

}