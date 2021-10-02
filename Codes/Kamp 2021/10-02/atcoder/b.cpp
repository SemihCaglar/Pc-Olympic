#include<semih/competitive.h>

string a,b;
bool s;

int main(){
    fast;
    // test();
    cin>>a>>b;

    for(int i=0;i<a.length();++i)
        if(a[i]!=b[i]){
            if(i==a.length()-1 or s){
                cout<<"No\n";
                return 0;
            }
            swap(b[i],b[i+1]);
            s=true;
        }
    cout<<"Yes\n";
    

    return 0;
}