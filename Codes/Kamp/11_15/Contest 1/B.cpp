#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int a=0;
    for(auto i:s)
        if(i=='a')
            a++;
    int len=s.length();
    if(a>len-a){
        cout<<len;
        return 0;
    }
    cout<<a+a-1<<endl;

}