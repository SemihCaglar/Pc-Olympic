#include "sequence.h"

#include <vector>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

#define fi first
#define se second
#define pb push_back

int sequence(int N, std::vector<int> A) {
    int ans=-1;
    for(int i=0;i<N;++i){
        for(int j=i;j<N;++j){
            vi v;
            map<int,int> mp;
            for(int k=i;k<=j;++k){
                v.pb(A[k]);
                mp[A[k]]++;
            }
            sort(v.begin(),v.end());
            int x1=v[(v.size()-1)/2];
            int x2=v[(v.size()+1)/2];
      
            ans=max(ans,mp[x1]);
            if(v.size()!=1){
                ans=max(ans,mp[x2]);
            }
        }
    }
    return ans;
}
