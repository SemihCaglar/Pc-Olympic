#include<bits/stdc++.h>
using namespace std;
 
long long int n,last,sum;
 
int main(){
	cin>>n;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		if(i==0)
			last=x;
		if(x<last)
			sum+=last-x,x=last;
		last=x;
	}
	cout<<sum<<"\n";
}