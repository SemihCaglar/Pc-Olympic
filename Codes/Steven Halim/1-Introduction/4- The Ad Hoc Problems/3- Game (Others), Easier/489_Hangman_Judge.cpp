#include<bits/stdc++.h>
using namespace std;

int tur;
string kelime,tahmin;

int main(){
    while(cin>>tur,tur!=-1){
        cin>>kelime>>tahmin;
        multiset<char> st;
        for(auto i:kelime)
            st.insert(i);
        int wrong=0;
        bool flag=false;
        for(auto i:tahmin){
            if(st.count(i)==0){
                wrong++;
                if(wrong==7)
                    break;
            }
            else{
                st.erase(i);
                if(st.empty()){
                    flag=true;
                    break;
                }
            }
        }
        cout<<"Round "<<tur<<'\n';
        if(flag)
            cout<<"You win.\n";
        else if(wrong==7)
            cout<<"You lose.\n";
        else
            cout<<"You chickened out.\n";
    }
}