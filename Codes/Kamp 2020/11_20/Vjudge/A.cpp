#include<bits/stdc++.h>
using namespace std;

void f(multiset<int>::iterator it,multiset<int>::iterator begin){
    int cnt=1;
    for(;begin!=it;begin++);
    cout<<"***"<<cnt<<"***\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,medyan=0x7fffffff;
        multiset<int> st;
        multiset<int>::iterator it=st.begin();
        while(cin>>a,a!=0){
            if(a==-1){
                cout<<*it<<'\n';
                auto tmp=it;
                if(st.size()%2==0)
                    it++;
                else
                    it--;
                st.erase(tmp); 
                medyan=*it;     
            }
            else{
                st.insert(a);
                if(st.size()==1)
                    it++;
                if(a<medyan){
                    if(st.size()%2==0){
                       it--;
                       medyan=*it;
                    }
                    else if(st.size()==1)
                        medyan=a;        
                }
                else if(st.size()%2==1){
                    it++;
                    medyan=*it;                         
                }
            }
        }

    }
}