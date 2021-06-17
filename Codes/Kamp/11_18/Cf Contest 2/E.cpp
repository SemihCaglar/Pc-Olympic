#include<bits/stdc++.h>
using namespace std;

vector<int> bira;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        bira.push_back(a);
    }
    sort(bira.begin(),bira.end());

    int q;
    cin>>q;
    for(int i=0;i<q;++i){
        int a;
        cin>>a;
        if(a>*bira.rbegin()){
            cout<<bira.size()<<'\n';
            continue;
        }
        auto oluru=upper_bound(bira.begin(),bira.end(),a);
        if(oluru==bira.begin()){
            cout<<0<<'\n';
            continue;
        }
        oluru--;
        cout<<oluru-bira.begin()+1<<'\n';
    }
}