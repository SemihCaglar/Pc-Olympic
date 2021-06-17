#include<semih/competitive.h>

const int N=505;

int n;
int a[N][N];
bool flag=true;

bool olur(int i,int j){
    if(i<0 or i>=n or j<0 or j>=n or j>i)
        return false;
    return !a[i][j];
}

void doldur(int i,int j,int &x,int g){
    if(x==0)
        return;
    x--;
    a[i][j]=g;
    
    if(olur(i,j+1)){
        doldur(i,j+1,x,g);
    }
    if(olur(i+1,j)){
        doldur(i+1,j,x,g);
    }
    if(olur(i,j-1)){
        doldur(i,j-1,x,g);
    }
    if(x!=0){
        flag=false;
        return;
    }

}

int main(){
    fast;
    test();

    cin>>n;
    forr(i,0,n)
        cin>>a[i][i];

    for(int i=n-1;i>=0;i--){
        int tmp=a[i][i];
        doldur(i,i,tmp,a[i][i]);
        if(flag==false){
            cout<<-1;
            return 0;
        }
    }
    forr(i,0,n){
        forr(j,0,i+1)
            cout<<a[i][j]<<sp;
        cout<<"\n";
    }
    return 0;
}