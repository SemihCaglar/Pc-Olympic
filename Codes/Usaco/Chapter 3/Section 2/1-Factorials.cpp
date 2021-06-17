#include<semih/competitive.h>

int n;

int res=1;
int iki,bes;

void solve(){
	cin>>n;
	for(int i=2;i<=n;++i){
		int x=i;
		while(x%2==0)
			iki++,x/=2;
		while(x%5==0)
			bes++,x/=5;
		res*=x;
		res%=10;
	}
	for(int i=0;i<iki-bes;++i)
		res*=2,res%=10;
	cout<<res<<endl;
}