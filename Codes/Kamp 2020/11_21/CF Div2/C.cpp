#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int N='z'-'a'+1;

int t,n,k;
string a,b;
int sayi[30];

int main(){
    cin>>t;
    while(t--){
        set<int> harfler[30];
        bool flag=false;
        for(int i=0;i<N;++i)
            sayi[i]=0;
        cin>>n>>k>>a>>b;
        for(auto i:a)
            sayi[i-'a']++;

        auto it=harfler[0].begin();
        char harf=b[0];
        int cur=0;
        for(int i=1;i<k;++i){
            if(b[i]!=harf){
                int adet=i-cur;
                if(adet==1){
                    if(sayi[harf-'a']==0){
                        cout<<"NO\n";
                        flag=true;
                        break;
                    }
                    sayi[harf-'a']--;
                }
                cur=i;
                harf=b[i];   
            }
        }
        if(flag)
            continue;
        int adet=k-cur;
        if(adet==1){
            if(sayi[harf-'a']==0){
                cout<<"NO\n";
                flag=true;
            }
            sayi[harf-'a']--;
        }
        if(flag)
            continue;
        
        for(int i=0;i<N;++i){
            harfler[ sayi[i] ].insert(i);
        }
        harf=b[0],cur=0;
        for(int i=1;i<k;++i){
            if(b[i]!=cur){
                int adet=i-cur;
                if(adet==1)
                    continue;
                auto it=harfler[adet].upper_bound(harf-'a');
                if(it==harfler[adet].begin()){
                    cout<<"NO\n";
                    flag=true;
                    break;
                }
                it--;
                harfler[adet].erase(it);
                cur=i;
                harf=b[i];
            }
        }
        if(flag)
            continue;
        
        adet=k-cur;
        if(adet==1)
            continue;
        it=harfler[adet].upper_bound(harf-'a');
        if(it==harfler[adet].begin()){
            cout<<"NO\n";
            flag=true;
        }
        if(flag)
            continue;
        it--;
        harfler[adet].erase(it);
        
        cout<<"YES\n";    
    }
}