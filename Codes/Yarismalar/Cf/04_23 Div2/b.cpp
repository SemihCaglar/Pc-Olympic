#include<semih/competitive.h>

int t;
int n,m;
vector<multiset<int>> v;
vector<ii> neblm;
vector<vector<int>> ans;

int main(){
    fast;
    // test();
    cin>>t;
    while(t--){
        cin>>n>>m;
        forr(i,0,n){
            multiset<int> tmp;
            v.pb(tmp);
            forr(j,0,m){
                int a;
                cin>>a;
                v[i].insert(a);
                neblm.pb({a,i});
            }
        }

        sort(all(neblm));
        int ind=0;
        forr(i,0,m){
            ii next=neblm[ind];
            if(v[next.se].count(next.fi)==false){
                ind++;
                continue;
            }
            vi tmp;
            ans.pb(tmp);
            forr(j,0,n){
                if(j==next.se){
                    ans[i].pb(next.fi);
                    v[j].erase(v[j].find(next.fi));
                    continue;
                }
                ans[i].pb(*v[j].rbegin());
                v[j].erase(v[j].find(*v[j].rbegin()));

            }
            ind++;
        }
        forr(i,0,n){
            forr(j,0,m)
                cout<<ans[j][i]<<sp;
            cout<<"\n";
        }
        forr(i,0,n)
            ans[i].clear();
        ans.clear();
        forr(i,0,n)
            v[i].clear();
        v.clear();
        neblm.clear();
    }

    return 0;
}