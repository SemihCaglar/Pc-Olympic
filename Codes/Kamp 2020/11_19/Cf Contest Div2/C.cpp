#include<bits/stdc++.h>
using namespace std;
int t;
string s;

int main(){
    cin>>t;
    while(t--){
        cin>>s;
        int parantez[2][2]={0}; // 2 tane parantez var. Her ikisinde de açılma veya kapanma var.
        int cnt=0;
        for(auto i:s){
            switch(i){
                case '(': parantez[0][0]++; break;
                case '[': parantez[1][0]++; break;
                case ']': if(parantez[1][0]>0){
                    cnt++;
                    parantez[1][0]--;
                }
                break;
                case ')':if(parantez[0][0]>0){
                    cnt++;
                    parantez[0][0]--;
                }
            }
        }
        cout<<cnt<<'\n';
    }
}