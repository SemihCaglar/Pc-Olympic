#include<bits/stdc++.h>
using namespace std;
 
int n;
set<int> st;
 
int main(){
	cin>>n;
	for(int i=1;i<n;++i){
		int x;
		cin>>x;
		st.insert(x);
	}
	for(int i=1;i<=n;++i)
		if(st.count(i)==false){
			cout<<i<<"\n";
			return 0;
		}
}