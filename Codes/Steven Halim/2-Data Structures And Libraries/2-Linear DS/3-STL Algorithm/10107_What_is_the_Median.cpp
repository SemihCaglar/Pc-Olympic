#include<semih/competitive.h>

vi v;

void solve(){
    int tmp;
    while(cin>>tmp){
        v.push_back(tmp);
        for(int i=v.size()-1;i>0 and v[i]>v[i-1];--i)
            swap(v[i],v[i-1]);
        if(v.size()%2)
            cout<<v[ v.size()/2 ]<<'\n';
        else
            cout<<( v[ v.size()/2 ]+v[ v.size()/2-1 ] )/2<<'\n';
    }     
}
