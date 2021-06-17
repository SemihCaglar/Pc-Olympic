#include<semih/competitive.h>

typedef pair<string,int> si;

map<string,si>  path;
map<string,int> dist;

string bir(string s){
    string tmp="";
    for(int i=7;i>=4;--i)
        tmp+=s[i];
    for(int i=3;i>=0;--i)
        tmp+=s[i];
    return tmp;
}
string iki(string s){
    string tmp=s;

    swap(tmp[0],tmp[3]);
    swap(tmp[3],tmp[2]);
    swap(tmp[2],tmp[1]);

    swap(tmp[7],tmp[4]);
    swap(tmp[5],tmp[4]);
    swap(tmp[5],tmp[6]);

    return tmp;
}
string uc(string s){
    string tmp=s;
    swap(tmp[1],tmp[2]);
    swap(tmp[1],tmp[5]);
    swap(tmp[1],tmp[6]);
    return tmp;
}

int f(string s){
    typedef struct neblm{
        string s;
        int deg;
        string prev;
        int choice;
    }neblm;

    queue<neblm> q;
    map<string,bool> vis;
    q.push(neblm{"12345678",0,"12345678",-1});
    while(!q.empty()){
        neblm tmp=q.front();
        q.pop();
        if(vis[tmp.s])
            continue;
        path[tmp.s]=si(tmp.prev,tmp.choice);
        vis[tmp.s]=true;
        q.push(neblm{bir(tmp.s),tmp.deg+1,tmp.s,1});
        q.push(neblm{iki(tmp.s),tmp.deg+1,tmp.s,2});
        q.push(neblm{uc(tmp.s),tmp.deg+1,tmp.s,3});
        if(tmp.s==s)
            return tmp.deg;
    }
    return 5;
}

int cnt;

void yazdir(string s){
    if(path[s].se!=-1){
        yazdir(path[s].fi);
        if(cnt==60)
            cout<<'\n',cnt=0;
    }
    switch(path[s].se){
        case -1: break;
        case 1: cout<<"A";cnt++; break;
        case 2: cout<<"B";cnt++; break;
        case 3: cout<<"C";cnt++; break;
    }
}

void solve(){
    freopen("/home/semihcaglar/Desktop/Pc Olympic/test/test.err","w",stderr);
    string tmp="";
    forr(i,0,8){
        char a;
        cin>>a;
        tmp+=a;
    }
    if(tmp=="12345678"){
        cout<<"0\n\n";
        return;
    }
    cout<<f(tmp)<<'\n';
    yazdir(tmp);
    if(cnt)
        cout<<"\n";
}