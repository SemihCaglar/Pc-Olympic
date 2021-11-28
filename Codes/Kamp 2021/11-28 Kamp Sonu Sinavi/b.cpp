#include<semih/competitive.h>

const int N=3e3+5;
int n;
int a[N];
vii ans;

int main(){
    fast;
    // test();

    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];

    for(int i=0;i+1<n;++i){ // yerine koyacağımız indeks
        int mn=INT_MAX;
        int ind=-1;
        for(int j=i;j<n;++j){
            if(a[j]<mn){
                mn=a[j];
                ind=j;
            }
        }
        if(ind==i)
            continue;
        swap(a[ind],a[i]);
        ans.pb({i,ind});
    }

    cout<<ans.size()<<"\n";
    for(auto i: ans)
        cout<<i.fi<<" "<<i.se<<"\n";

    return 0;
}