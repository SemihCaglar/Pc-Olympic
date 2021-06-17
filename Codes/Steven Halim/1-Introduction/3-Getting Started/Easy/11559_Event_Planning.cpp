#include<bits/stdc++.h>
using namespace std;
const int INF=0x7fffffff;

int mn;
int n,para,otel,hafta;

int main(){
    while(cin>>n>>para>>otel>>hafta){
        mn=INF;
        for(int i=0;i<otel;++i){
            int butce;
            cin>>butce;
            int mx=0;
            for(int j=0;j<hafta;++j){
                int a;
                cin>>a;
                mx=max(mx,a);
            }
            if(mx>=n)
                mn=min(mn,n*butce);
        }
        if(mn>para)
            cout<<"stay home\n";
        else
            cout<<mn<<'\n';
    }
}