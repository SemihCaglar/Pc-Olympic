#include<bits/stdc++.h>
using namespace std;

int n,t;

int main(){
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int result;
		switch(n){
			case 1: result=0; break;
			case 2: result=1; break;
			case 3: result=2; break;
			default: if(n%2==0){result=2;}
					else{result=3;}
		}
		cout<<result<<'\n';
	}

}
