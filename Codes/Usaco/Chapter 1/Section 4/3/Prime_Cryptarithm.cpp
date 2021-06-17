/*
ID: semihca1
TASK: crypt1
LANG: C++                 
*/
#define isim  "crypt1"

#include<bits/stdc++.h>
using namespace std;

vector<int> numbers;
int n;

bool control(int n){
    stringstream s;
    s<<n;
    char c;
    while(s>>c){
        bool hey=false;
        for(auto i:numbers)
            if(c-'0'==i){
                hey=true;
                break;
            }
        if(!hey)
            return false;
    }
    return true;
}

int main() {
    //freopen( &*(string(isim)+".in").begin() , "r" , stdin );
    //freopen( &*(string(isim)+".out").begin() , "w" , stdout );
    cin>>n;
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        numbers.push_back(a);
    }
    #define fori(i) for(auto i:numbers)
    int cnt=0;
    fori(a)
        fori(b)
            fori(c)
                fori(d)
                    fori(e){
                        if((!a&&!b&&!c)||(!d&&!e))
                            continue;
                        int abc=100*a+10*b+c;
                        int p1=abc*e;
                        int p2=abc*d;
                        if(control(p1)&&control(p2)&& (p1>=1e2&&p1<1e3) && (p2>=1e2&&p2<1e3) ){
                            int result=p1+10*p2;
                            if(control(result)&&result>=1e3&&result<1e4)
                                cnt++;
                        }
                    }
    
    cout<<cnt<<endl;
}    