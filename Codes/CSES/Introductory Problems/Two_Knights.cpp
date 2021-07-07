#include<bits/stdc++.h>
using namespace std;
 
unsigned long long n;
 
int main(){
	cin>>n;
    for(unsigned long long i=1;i<=n;++i)
        cout<< ( i*i*(i*i-1) - 8*(i-1)*(i-2) ) / 2<<"\n";
}