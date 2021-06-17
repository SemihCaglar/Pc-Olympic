#include<semih/competitive.h>

int t,cnt;
class cont{
    public:
    cont(){
        solved=0;
        totpen=-1;
    }
    void final(){
        int sum=0;
        for(auto i:penalty)
            if(i.se>=0){
                sum+=i.se;
                solved++;
        }
        totpen=sum;
    }
    bool operator<(cont x){
        if(solved!=x.solved)
            return solved>x.solved;
        if(totpen!=x.totpen)
            return totpen<x.totpen;
        return team<x.team;
    }
    int totpen;
    int solved;
    int team;
    map<int,int> penalty; // WA eksi olacak, AC geldiğinde hepsi toplancak.
};

void solve(){
    cin>>t;
    string tmp;
    getline(cin,tmp);
    getline(cin,tmp);
    
    while(t--){
        unordered_map<int,cont> mp;
        while(getline(cin,tmp),tmp!=""){
            stringstream s;
            s<<tmp;
            int n,prob,time;
            char le;
            s>>n>>prob>>time>>le;

            cont &person=mp[n];
            if(le=='C'){
                if(person.penalty.count(prob)==0)
                    person.penalty[prob]=time;
                else if(person.penalty[prob]<0){
                    person.penalty[prob]*=-1;
                    person.penalty[prob]+=time;
                }
            }
            else if(le=='I'){
                if(person.penalty.count(prob)==0){
                    person.penalty[prob]= -20;
                }
                else if(person.penalty[prob]<0){
                    person.penalty[prob]+= -20;
                }
            }

        }
        vector<cont> v;
        for(auto &i:mp){
            i.second.final();
            i.second.team=i.first;
            v.pb(i.se);
        }
        sort(all(v));
        if(cnt)
            cout<<'\n';
        for(auto i:v)
            cout<<i.team<<sp<<i.solved<<sp<<i.totpen<<'\n';
        cnt++;
    }
}