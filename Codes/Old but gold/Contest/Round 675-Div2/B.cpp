#include<bits/stdc++.h>
using namespace std;
typedef long long int ulli;

const int N=105;
int n,m;
int arr[N][N];

ulli abss(ulli a){
    if(a>0) return a;
    return -a;
}

ulli minimum(int a,int b,int c,int d){
    int neblm[4]={a,b,c,d};
    sort(neblm,neblm+4);
    int medyan=(neblm[1]+neblm[2])/2;
    return abss(medyan-a)+abss(medyan-b)+abss(medyan-c)+abss(medyan-d);
}

ulli min2(int a,int b){
    ulli ort=(0LL+a+b)/2;
    ulli gereken1=abss(ort-a)+abss(ort-b);
    return gereken1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        ulli cnt=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j)
                cin>>arr[i][j];
        }
        int ust=0,alt=n-1;
        while(true){
            int sol=0,sag=m-1;
            if(ust<alt){
            while(true){
                if(sol==sag)
                    cnt+=min2(arr[ust][sol],arr[alt][sol]);
                else
                   cnt+=minimum(arr[ust][sol],arr[ust][sag],arr[alt][sol],arr[alt][sag]);
                sol++;
                sag--;
                if(sol>sag)
                    break;
            }
            }
            if(ust==alt){
                while(true){
                    if(sol==sag)
                        break; 
                    else
                        cnt+=min2(arr[ust][sol],arr[ust][sag]);
                    
                    sol++;
                    sag--;
                    if(sol>sag)
                        break;
                } 
            }
            ust++;
            alt--;
            if(ust>alt)
                break;
        }
        cout<<cnt<<"\n";
    }
}