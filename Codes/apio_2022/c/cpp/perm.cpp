#include "perm.h"

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

#define pb push_back
#define fi first 
#define se second

std::vector<int> construct_permutation(long long k){
	k--;

	if(k==0){
		vi tmp;
		return tmp;
	}
	if(k==1){
		vi tmp;
		tmp.pb(0);
		return tmp;
	}
	vi tmp; // 2 uzeri sayilar
	for(int i=60;i>0;--i){
		if(k>=(1LL<<i)){
			tmp.pb(i);
			k-=(1LL<<i);
		}
	}
	int cnt=0;
	if(k)
		cnt++;

	vi ans;
	int prev=0;
	for(auto i: tmp){
		for(int j=prev+i;j>prev;--j){
			ans.pb(j-1);
		}
		prev+=i;
		cnt++;
	}

	tmp.clear();
	tmp=construct_permutation(cnt+1);
	reverse(tmp.begin(),tmp.end());

	for(auto i: tmp)
		ans.pb(prev+i);

	reverse(ans.begin(),ans.end());

	return ans;
}