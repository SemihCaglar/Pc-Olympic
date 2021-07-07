#include<bits/stdc++.h>
using namespace std;
 
string s;
 
int main(){
	cin>>s;
	int mx=0;
	for(int i=0;i<s.length();++i){
		int c;
		for(c=1;i+1<s.length() and s[i+1]==s[i];i++,c++);
		mx=max(mx,c);
	}	
	cout<<mx<<"\n";
}