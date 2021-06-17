#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ulli;
typedef pair<ulli,int> ii;

int n;
string s;
bool sifir[15];
ii carpan[15];
int hangisisifir=-1;

int hizlius(int a,int b){
    if(b==0)
        return 1;
    int c=hizlius(a,b/2);
    if(b%2==0)
        return c*c;
    return c*c*a;
}

bool cmp(ii a,ii b){
    return a>b;
}

int main(){
    cin>>n;
    for(int i=0;i<10;++i){
        carpan[i].second=i;
    }
    for(int i=0;i<n;++i){
        cin>>s;
        sifir[s[0]-'a']=true;
        int len=s.length();
        for(int i=0;i<len;++i){
            carpan[s[i]-'a'].first+=hizlius(10,len-i-1);
        }
    }
    sort(carpan,carpan+10,cmp);
    ulli sum=0;
    for(int i=0;i<10;++i){
        if(sifir[ carpan[i].second ]==false){
            hangisisifir=carpan[i].second;
            break;
        }
    }
    int kalan=1;
    for(int i=0;i<10;++i){
        if(carpan[i].second==hangisisifir){
            continue;
        }
        sum+=carpan[i].first*kalan;
        kalan++;
    }
    cout<<sum;
}
