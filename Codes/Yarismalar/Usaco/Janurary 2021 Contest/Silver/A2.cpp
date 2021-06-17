#include<bits/stdc++.h>
using namespace std;
#define test freopen("/home/semih/Desktop/Pc Olympic/test/test.in","r",stdin);freopen("/home/semih/Desktop/Pc Olympic/test/test.out","w",stdout)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int N=2e5+5;

int n,k;
int location[N];
pair<int,int> input[N];
set<int> neblm[N];


int main(){
    fast;
    // test;

    cin>>n>>k;
    for(int i=0;i<n;++i)
        location[i]=i;
    for(int i=0;i<k;++i){
        int a,b;
        cin>>a>>b;
        a--,b--;
        input[i]=make_pair(a,b);
        neblm[location[a]].insert(b);
        neblm[location[b]].insert(a);
        swap(location[a],location[b]);
    }
    // for(int i=0;i<n;++i){
    //     cout<<i<<endl;
    //     for(auto j:neblm[i])
    //         cout<<j<<' ';
    //     cout<<endl<<endl;
    // }
    for(int i=0;i<n;++i){
        // cout<<"Hey"<<n<<' ';
        set<int> tmp;
        tmp.insert(i);
        set<int> vis;
        vis.insert(i);
        for(auto j:neblm[i])
            tmp.insert(j);
        int a=i;
        while(a!=location[a] and vis.count(location[a])==0){
            for(auto j:neblm[location[a]])
                tmp.insert(j);
            a=location[a];
            // cout<<"Hey "<<i<<location[i]<<endl<<endl;
            vis.insert(a);
        }
        // cout<<"Hoo"<<endl;
        cout<<tmp.size()<<'\n';

    }


    
}