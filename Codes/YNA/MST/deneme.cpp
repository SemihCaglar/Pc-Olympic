#include<semih/competitive.h>

const int N=2e5+5;
typedef pair<int,ii> edge;

int n,m;
int parent[N];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}

int cevap[N];

void solve(){
	cin>>n>>m;
	
	vector<pair<edge,int>> v; // (edge,indeks)
	
	for(int i=1;i<=n;++i)
		parent[i]=i;
	for(int i=1;i<=m;++i){
		int a,b,w;
		cin>>a>>b>>w;
		edge tmp=edge(w,ii(a,b));
		v.pb(_mp(tmp,i));
	}
	sort(all(v));

	int cnt=0;
	
	for(int i=0;i<m;++i){
		int agirlik=v[i].fi.fi;
		int tmp=0;
		for(int j=i;j<m;++j){
			int a=v[j].fi.se.fi,b=v[j].fi.se.se,w=v[j].fi.fi;
			if(w!=agirlik)
				break;
			if(find_set(a)!=find_set(b))
				tmp++;
		}
		if(cnt+tmp<=n-1){
			for(int j=i;j<m;++j){
				int a=v[j].fi.se.fi,b=v[j].fi.se.se,w=v[j].fi.fi;
				if(w!=agirlik)
					break;
				if(find_set(a)!=find_set(b)){
					union_sets(a,b);
					cevap[ v[j].se ] = 1;
					cnt++;
				}
			}
		}
		else{
			for(int j=i;j<m;++j){
				int a=v[j].fi.se.fi,b=v[j].fi.se.se,w=v[j].fi.fi;
				if(w!=agirlik)
					break;
				if(find_set(a)!=find_set(b)){
					cevap[ v[j].se ] = 2;
				}
			}
		}

	}
	for(int i=1;i<=m;++i)
		cout<<cevap[i]<<endl;

}