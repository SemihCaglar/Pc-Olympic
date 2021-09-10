#include<bits/stdc++.h>
using namespace std;
#define st first
typedef long long ll;
typedef pair<int,int> ii;

const int N=2e5+5;
ll presum[N];
unsigned long long int W;
int t,n;
ii weight[N]; // (agirlik,index)

int main(){
    cin>>t;
    while(t--){
        cin>>n>>W;
        for(int i=1;i<=n;++i){
            int a;
            cin>>a;
            weight[i]=ii(a,i);
        }
    }
    sort(weight,weight+n);
    presum[0] = weight[0].st;
    for(int i=1;i<n;++i){
        presum[i] = presum[i-1] + weight[i].st;
    }
    if(presum[n-1] < W/2)
        cout << -1 << "\n";
    for(int i=0;i<n;i++){
        if(presum[i] >= W/2 && presum[i] <= W){

        }

    }

/* eğer çıkarınca sonuç n/2 ile n arasında ise çıkar ve return.
    eğer sonuç n den büyükse çıkar.
   6 12
   40
   
   25-20
   
   6 12
   5 6 
    5 5 5 5 -5
    presum[N];
    presum[0] = a[0];
    for(int i=1;i<nereyekadargidiyosa;++i){
           presum[i] += a[i] + presum[i-1]
    }
    5-10
    7 4 2
    16-32
    15 12 3
*/
}