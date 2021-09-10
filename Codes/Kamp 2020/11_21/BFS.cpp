#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int n,m,a,b;
vector<int> node[10];
queue<ii> q;
bool mark[10];

int main(){
	cin>>n>>m>>a>>b;
	for(int i=0;i<m;++i){
		int x,y;
		cin>>x>>y;
		node[x].push_back(y);
		node[y].push_back(x);
	}
	
	q.push(ii(a,0));
	while(!q.empty()){
		ii tmp=q.front();
		q.pop();
		if(mark[tmp.first])
			continue;
		for(int i=0;i<node[tmp.first].size();++i){
			int hedef=node[tmp.first][i];
			if(hedef==b){
				cout<<tmp.second+1<<endl;
				return 0;
			}
			if(!mark[hedef])
				q.push(ii(hedef,tmp.second+1));
		}
		mark[tmp.first]=1;
	}


}