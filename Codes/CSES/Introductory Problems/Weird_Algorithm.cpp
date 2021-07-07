#include<bits/stdc++.h>
using namespace std;
 
unsigned long long int  n;
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	while(n!=1){
		cout<<n<<" ";
		n= (n%2==0)?n/2:3*n+1;
	}
	cout<<1<<"\n";
}