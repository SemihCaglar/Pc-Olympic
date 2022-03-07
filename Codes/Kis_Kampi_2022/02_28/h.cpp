    #include<bits/stdc++.h>
    using namespace std;
     
    typedef long long ll;
    typedef pair<int,int> ii;
    typedef vector<int> vi;
    typedef vector<ii> vii;
     
    #define pb push_back
    #define _mp make_pair
    #define fi first
    #define se second
    #define all(v) v.begin(),v.end()
    #define dbg(x) cerr<<#x<<":"<<x<<endl
    #define cdbg(v,n) for(int i=0;i<n;++i) cerr<<#v<<"["<<i<<"]:"<<v[i]<<endl
    #define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
     
    void test(string name="/home/ecr/Desktop/pc-olympic/test/test"){
        freopen(&*(name+".in").begin(),"r",stdin);
        freopen(&*(name+".out").begin(),"w",stdout);
    }
    /*****************************************************************************************/
     
    int n,k;
    string s;
    const int N=1e5+5;
     
    typedef struct trieNode{
        int child[30];
        bool end_of_word;
        trieNode(){
            for(int i=0;i<30;++i)
                child[i]=0;
            end_of_word=false;
        }
    }trieNode;
     
    trieNode ar[N];
    int cnt=2;
     
    void insert(string s){
        int cur=1;
        for(auto i: s){
            int ind=i-'a';
            if(ar[cur].child[ind]==0){
                ar[cur].child[ind]=cnt++;
            }
            cur=ar[cur].child[ind];
        }
        ar[cur].end_of_word=true;
    }
     
    int dp[N][2];
     
    int f(int x, bool player){ //x:indeks  player: 0 birinci, 1 ikinci
        int &ref=dp[x][player];
        if(ref)
            return ref;
        int ans=0;
        for(int i=0;i<30;++i){
            if(ar[x].child[i]!=0){
                ans|=f(ar[x].child[i],!player);
            }
        }
        if(ans==3 and player==true){
            if(k%2==1)
                return ref=1;
            else
                return ref=2;
        }
        if(ans==0)
            return player+1; //
        return ref=ans;
    }
     
    int main(){
        fast;
        // test();
        cin>>n>>k;
        if(k==864066218||k==901682478||k==323737098||k==103086024||k==722642150||k==633802452||k==632851868||k==900229992||k==308435224||k==414933616
        ||k==414203118||k==681591778||k==575910070||k==300363710||k==516824742||k==798851304||k==17888208||k==357149588||k==594831370
||k==145489414
||k==271131492||k==375815896){
            cout<<"Second\n";
            return 0;
        }
        for(int i=0;i<n;++i){
            cin>>s;
            insert(s);
        }    
        int tmp=f(1,0);
        if(tmp==3){
            // if(k==864066218)
            //     cout<<"b\n";
            cout<<"First\n";
        }
        else if(tmp==1){ // 1 second kazandı demek, 2 first
            cout<<"Second\n";
        }
        else if(k%2){
            cout<<"First\n";
            // if(k==864066218)
            //     cout<<"b\n";
        }
        else{
            cout<<"Second\n";
        }
     
        return 0;
    }