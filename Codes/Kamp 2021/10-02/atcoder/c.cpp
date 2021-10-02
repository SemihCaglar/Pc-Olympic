#include<semih/competitive.h>

string s;
long long mx=-1;

int main(){
    fast;
    // test();

    cin>>s;
    sort(all(s));
    do{
        if(s[0]=='0')
            continue;
        for(int i=1;i<s.length();i++){
            if(s[i]!='0'){
                string a,b;
                a=s.substr(i);
                b=s.substr(0,i);
                mx=max(mx, 1LL*stoi(a)*stoi(b) );
            }
        }
    }
    while(next_permutation(all(s)));

    cout<<mx<<"\n";

    return 0;
}