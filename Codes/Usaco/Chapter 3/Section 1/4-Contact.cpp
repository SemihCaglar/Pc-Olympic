#include<semih/competitive.h>

int a,b,n;
string s;
struct cmpByStringLength {
    bool operator()(const std::string& a, const std::string& b) const {
        if(a.length()!=b.length())
            return a.length() < b.length();
        return a<b;
    }
};

void solve(){
    cin>>a>>b>>n>>s;
    string tmp;
    while(cin>>tmp)
        s+=tmp;
    map<string,int,cmpByStringLength> mp;
    forr(i,a,b+1){
        for(int j=0;j+i<=s.length();++j){
           string tmp=s.substr(j,i);
           mp[tmp]++;
        }
    }
    typedef pair<string,int> si;
    int prev=-1;
    int cnt=0;
    bool ilk=true;
    for(int i=0;i<=n;){
        if(mp.empty())
            break;
        si mx=si("",-1);
        for(auto j:mp){
            if(j.se>mx.se){
                mx=j;
            }
        }
        if(mx.se!=prev){
            if(i==n)
                break;
            if(!ilk)
                cout<<'\n';
            else
                ilk=false;
            cout<<mx.se<<'\n';
            cnt=0;
            prev=mx.se;
            ++i;
        }
        else{
            cnt++;
            if(cnt==6){
                cout<<'\n';
                cnt=0;
            }
        }
        if(cnt)
            cout<<' ';
        cout<<mx.fi;
        mp.erase(mx.fi);
    }
    cout<<endl;

}