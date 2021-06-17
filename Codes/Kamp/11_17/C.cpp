#include<bits/stdc++.h>
using namespace std;
int t,n,m;
char matr[105][105];

int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                cin>>matr[i][j];
        int cnt[2]={0,0}; // 0,1
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j){
                cnt[matr[i][j]-'0']++;
            }
        int enter=0;
        if(cnt[1]%3==0){
            cout<<cnt[1]/3<<'\n';
            for(int i=0;i<n;++i)
                for(int j=0;j<m;++j){
                    if(matr[i][j]=='1'){
                        cout<<i+1<<' '<<j+1<<' ';
                        enter++;
                        if(enter==3){
                            cout<<'\n';
                            enter=0;
                        }
                    }
                }
        }
        else if(cnt[1]%3<=cnt[0]){
            int a=cnt[1]%3;
            cout<<cnt[1]/3+1<<'\n';
            for(int i=0;i<n;++i)
                for(int j=0;j<m;++j){
                    if(matr[i][j]=='0'&&a){
                        cout<<i+1<<' '<<j+1<<' ';
                        a--;
                        matr[i][j]='1';
                        if(a==0){
                            i+=n+5;
                            j+=m+5;
                        }
                        enter++;
                        if(enter==3){
                            cout<<'\n';
                            enter=0;
                        }
                    }
                }
            for(int i=0;i<n;++i)
                for(int j=0;j<m;++j){
                    if(matr[i][j]=='1'){
                        cout<<i+1<<' '<<j+1<<' ';
                        enter++;
                        if(enter==3){
                            cout<<'\n';
                            enter=0;
                        }
                    }
                }

        }
        else{
            int a=3;
            cout<<cnt[1]/3+1<<'\n';
            for(int i=0;i<n;++i)
                for(int j=0;j<m;++j){
                    if(matr[i][j]=='1'&&a){
                        cout<<i+1<<' '<<j+1<<' ';
                        a--;
                        matr[i][j]='0';
                        if(a==0){
                            i+=n+5;
                            j+=m+5;
                        }
                        enter++;
                        if(enter==3){
                            cout<<'\n';
                            enter=0;
                        }
                    }
                }
                
            a=cnt[1]%3;
            for(int i=0;i<n;++i)
                for(int j=0;j<m;++j){
                    if(matr[i][j]=='0'&&a){
                        cout<<i+1<<' '<<j+1<<' ';
                        a--;
                        matr[i][j]='1';
                        if(a==0){
                            i+=n+5;
                            j+=m+5;
                        }
                        enter++;
                        if(enter==3){
                            cout<<'\n';
                            enter=0;
                        }
                    }
                }
            for(int i=0;i<n;++i)
                for(int j=0;j<m;++j){
                    if(matr[i][j]=='1'){
                        cout<<i+1<<' '<<j+1<<' ';
                        enter++;
                        if(enter==3){
                            cout<<'\n';
                            enter=0;
                        }
                    }
                }
        }
    }
}