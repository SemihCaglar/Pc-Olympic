#include<bits/stdc++.h>
using namespace std;
 
unsigned long long int n;
 
int main(){
	cin>>n;
    unsigned long long int sum=n*(n+1)/2;
    if(sum%2){
        cout<<"NO\n";
        return 0;
    }
    int last,ex;
    unsigned long long int top=0;
    for(int i=n;i;--i){
        if(top+i<=sum/2)
            top+=i;
        else{
            last=i+1;
            ex=sum/2-top;
            break;
        }
    }
    cout<<"YES\n"<<n-(last-1-(ex!=0))<<"\n";
    for(int i=last;i<=n;++i)
        cout<<i<<" ";
    if(ex!=0)
        cout<<ex<<"\n";
    cout<<last-1-(ex!=0)<<"\n";
    for(int i=1;i<last;++i)
        if(i!=ex)
            cout<<i<<" ";
    cout<<"\n";
}