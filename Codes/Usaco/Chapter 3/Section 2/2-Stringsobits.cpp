#include<semih/competitive.h>

int n,l;
ll k;

ll dp[40][40];

ll komb(int x,int y){
	if(y>x)
		return 0;
	if(dp[x][y]!=-1)
		return dp[x][y];
	if(y==0)
		return dp[x][y]=1;
	return dp[x][y]=komb(x-1,y-1)+komb(x-1,y);
}

string ans="";

void f(int ind){
	if(n==1)
		return;

	ll birolursa=0,sifirolursa=0;
	int oluru=n-ind;
	for(int j=0;j<=min(oluru,l);++j)
		sifirolursa+=komb(oluru,j);
	for(int j=0;j<=min(oluru,l-1);++j)
		birolursa+=komb(oluru,j);
	if(k<=sifirolursa){
		ans+="0";
		f(ind+1);
		return;
	}
	else if(k<=birolursa+sifirolursa){
		ans+="1";
		k-=sifirolursa;
		l--;
		f(ind+1);
		return;
	}

}

void solve(){
	cin>>n>>l>>k;
	forr(i,0,40)
		forr(j,0,40)
			dp[i][j]=-1;
	f(1);
	cout<<ans<<endl;
}
