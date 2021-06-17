#include<semih/competitive.h>

int hiz[7];
vii wheel[7];

bool check(){
	for(auto a:wheel[0])
		for(auto b:wheel[1])
			for(auto c:wheel[2])
				for(auto d:wheel[3])
					for(auto e:wheel[4])
						
						for(int v=1;v+3;v-=2)
							for(int x=1;x+3;x-=2)
								for(int y=1;y+3;y-=2)
									for(int z=1;z+3;z-=2)
										for(int t=1;t+3;t-=2){
											ii ar[5]={a,b,c,d,e};
											int arr[5]={v,x,y,z,t};

											for(int i=0;i<5;++i){
												ii &ref=ar[i];
												ref.se=ref.fi+ref.se;
												if(arr[i]==-1)
													ref.fi+=360,ref.se+=360;
											}
											ii tmp=ii(-1,INT_MAX);
											for(int i=0;i<5;++i){
												ii &ref=ar[i];
												tmp.fi=max(tmp.fi,ref.fi);
												tmp.se=min(tmp.se,ref.se);
											}
											if(tmp.fi<=tmp.se)
												return true;					
										}		
	return false;
}

void solve(){
	for(int i=0;i<5;++i){
		cin>>hiz[i];
		int k;
		cin>>k;
		for(int j=0;j<k;++j){
			int baslangic,aralik;
			cin>>baslangic>>aralik;
			wheel[i].pb(ii(baslangic,aralik));
		}
	}
	for(int sec=0;sec<=360;++sec){
		if(check()){
			cout<<sec<<endl;
			return;
		}
		for(int i=0;i<5;++i)
			for(auto &j:wheel[i])
				j.fi=(j.fi+hiz[i])%360;
	}
	cout<<"none\n";
}