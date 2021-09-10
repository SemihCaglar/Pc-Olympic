#include<bits/stdc++.h>
using namespace std;
int t,n,q;
string s;
int l,r;

bool f(){
    string alt=s.substr(l-1,r-l+1);
    bool bosluk=false;
    int ind=0;
    for(int i=0;i<n;++i){
        if(s[i]==alt[ind]){
            ind++;
            if(ind==alt.size())
                return true;
            if(!bosluk and ind==alt.size()-1)
                i++;
        }
        else if(ind>0)
            bosluk=true;
    }
    return false;
}

int main(){
    cin>>t;
    while(t--){
        cin>>n>>q;
        cin>>s;
        for(int i=0;i<q;++i){
            cin>>l>>r;
            bool sonuc=f();
            sonuc?cout<<"YES\n":cout<<"NO\n";
        }
    }
}
