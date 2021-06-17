#include<semih/competitive.h>
typedef pair<int,ii> iii;

int f(iii a,iii b){
	int bolum=-1;
	forr(i,0,3){
		int x,y;
		if(i==0)
			x=a.fi,y=b.fi;
		else if(i==1)
			x=a.se.fi,y=b.se.fi;
		else
			x=a.se.se,y=b.se.se;
			
		if(y==0){
			if(x!=0)
				return false;
			continue;
		}
		if(x%y)
			return false;
		if(bolum==-1)
			bolum=x/y;
		else if(x/y!=bolum)
			return false;
	}
	return bolum;
}

void solve(){
	iii goal,ar[4];
	int mn=400;

	cin>>goal.fi>>goal.se.fi>>goal.se.se;
	forr(i,0,3)
		cin>>ar[i].fi>>ar[i].se.fi>>ar[i].se.se;

	iii cevap=iii(-1,ii(-1,-1));
	int res;
	forr(i,0,100)
		forr(j,0,100)
			forr(k,0,100){
				int a=ar[0].fi*i + ar[1].fi*j + ar[2].fi*k ;
				int b=ar[0].se.fi*i + ar[1].se.fi*j + ar[2].se.fi*k ;
				int c=ar[0].se.se*i + ar[1].se.se*j + ar[2].se.se*k ;
				if(f( iii(a,ii(b,c)),goal ) and i+j+k<mn){
					mn=i+j+k;
					cevap=iii(i,ii(j,k));
					res=f( iii(a,ii(b,c)),goal );
				}
			}
	if(cevap.fi==-1)
		cout<<"NONE\n";
	else
		cout<<cevap.fi<<sp<<cevap.se.fi<<sp<<cevap.se.se<<sp<<res<<'\n';

}