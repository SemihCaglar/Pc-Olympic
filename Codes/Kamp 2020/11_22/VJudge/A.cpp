#include<bits/stdc++.h>
using namespace std;

vector<int> avengers;
int k,A,B;
long long n;

int dac(int l,int r){ // divide and conquer
    if(l==r){
        int cnt=upper_bound(avengers.begin(),avengers.end(),r)-lower_bound(avengers.begin(),avengers.end(),l);
        return cnt?cnt*B:A;
    }
    if(l>r){
        return 0x7fffffff;
    }
    int mid=(l+r)/2;
    int sol=dac(l,mid);
    int sag=dac(mid+1,r);
    int cnt=upper_bound(avengers.begin(),avengers.end(),r)-lower_bound(avengers.begin(),avengers.end(),l);
    int op2=cnt==0?A: (cnt*B*(r-l+1));
    return min(sag+sol,op2);
}

int main(){
    cin>>n>>k>>A>>B;
    n=1<<n;
    for(int i=0;i<k;++i){
        int a;
        cin>>a;
        avengers.push_back(a);
    }
    sort(avengers.begin(),avengers.end());
    cout<<dac(1,n);
}