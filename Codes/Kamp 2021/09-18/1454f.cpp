#include<semih/competitive.h>

const int N=2e5+5;
int t,n,a[N];
int logar[N];
int max_table[20][N];
int min_table[20][N];

int rmq(int l,int r,bool mode){
    int logaritma=logar[r-l+1];
    if(mode==0)
        return min( min_table[logaritma][l] , min_table[logaritma][r-(1<<logaritma)+1] );
    return max( max_table[logaritma][l] , max_table[logaritma][r-(1<<logaritma)+1] );
}

int main(){
    fast;
    // test();

    cin>>t;
    while(t--){

        cin>>n;
        for(int i=1,cnt=0;i<=n;i*=2,cnt++)
            for(int j=i;j<i*2;++j)
                logar[j]=cnt;
        for(int i=0;i<n;++i){
            cin>>a[i];
            max_table[0][i]=min_table[0][i]=a[i];
        }
        for(int i=1;i<=logar[n];++i)
            for(int j=0;j+(1<<i)<=n;++j){
                max_table[i][j]=max( max_table[i-1][j] , max_table[i-1][ j+ (1<<(i-1)) ] );
                min_table[i][j]=min( min_table[i-1][j] , min_table[i-1][ j+ (1<<(i-1)) ] );
            }
        int x=0,y=n-1;
        bool flag=false;

        while(x+1<y){
            int sag=rmq(y,n-1,1),sol=rmq(0,x,1);
            if(sag<sol)
                y--;
            else if(sag>sol)
                x++;
            else{
                int orta=rmq(x+1,y-1,0);
                if(orta==sag){
                    cout<<"Yes\n"<<x+1<<" "<<y-x-1<<" "<<n-y<<"\n";
                    flag=true;
                    break;
                }
                else if(a[x+1]<sol)
                    x++;
                else if(a[y-1]<sag)
                    y--;
                else if(a[x+1]==sol and a[y-1]!=sol)
                    x++;
                else if(a[y-1]==sol and a[x+1]!=sol)
                    y--;
                else{
                    int sonrakisag,sonrakisol;
                    sonrakisag=a[x+2];
                    sonrakisol=a[y-2];
                    if(sonrakisol<sol)
                        y--;
                    else if(sonrakisag<sol)
                        x++;
                    else if(sonrakisol==sol)
                        y--;
                    else
                        x++;
                }
            }
        }
        if(flag==false)
            cout<<"No\n";

    }    

    return 0;
}