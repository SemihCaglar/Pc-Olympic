#include<bits/stdc++.h>
using namespace std;

int main(){
    int mincift=11,neblm;
    string n;
    cin>>n;
    int son=n[n.length()-1]-'0';
    int cift,aa=-1;
    bool durum=false;
    for(int i=0;i<n.length();++i){
        if((n[i]-'0')%2==0){
            if(n[i]-'0'<mincift&&n[i]-'0'<son){
                mincift=n[i]-'0',neblm=i;
                durum=true;
                break;
            }
            else{
                aa=i;
            }
        }
    }
    if(!(mincift!=11||aa!=-1)){
        cout<<-1;
        return 0;
    }
    if(durum){
    swap(n[n.length()-1],n[neblm]);
    cout<<n;
    }
    else
    {
        swap(n[n.length()-1],n[aa]);
        cout<<n;
    }
    
}