#include<bits/stdc++.h>
using namespace std;
#define mtoh (1.0/12)
#define farktoaci (6.0)

int saat,dakika,tmp;

int main(){
	while(scanf("%d:%1d%1d",&saat,&tmp,&dakika),dakika=tmp*10+dakika,saat or dakika){
		double sonuc,dsaat=saat*5%60,ddakika=dakika;
		dsaat+=dakika*mtoh;
		sonuc=abs(dsaat-ddakika);
		sonuc=sonuc*farktoaci;
		sonuc=min(sonuc,360-sonuc);
		printf("%.3lf\n",sonuc);
	}
}
