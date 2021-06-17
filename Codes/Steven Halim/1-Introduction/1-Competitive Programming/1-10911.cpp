#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
ii coord[20];
double mx;
int n;
int part[20];

double dist(ii a,ii b){
    int x=abs(a.first-b.first);
    int y=abs(a.second-b.second);
    return sqrt(x*x+y*y);
}

void check(){
    double sum=0.0;
    bool vis[20]={0};
    for(int i=0;i<n;++i){
        if(vis[i]==false){
            vis[i]=true;
            vis[part[i]]=true;
            sum+=dist(coord[i],coord[part[i]]);
        }
    }
    mx=min(mx,sum);
}

void subset(int x){
    for(;x<=n and part[x];x++);
    if(x>n){
        check();
        return;
    }
    for(int i=x+1;i<=n;++i)
        if(!part[i]){
            part[i]=x;
            part[x]=i;
            subset(x+1);
            part[i]=0;
            part[x]=0;
        }
    
}

int main(){
    int cnt=0;
    while(cin>>n,n!=0){
        n=2*n;
        for(int i=1;i<=n;++i){
            string s;
            int x,y;
            cin>>s>>x>>y;
            coord[i]=ii(x,y);
        }
        memset(part,0,sizeof(part));
        mx=0x7fffffff;
        subset(1);
        printf("Case %d: %.2lf\n",++cnt,mx);
    }

}