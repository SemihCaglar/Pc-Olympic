#include<semih/competitive.h>

string s,b;
const int M=1e9+7,P=29;
int bad[1505];
int k;
long long h[1505];
map<int,int> ans;
int inv;

int fast_pow(int x, int y){
    if(y==0)
        return 1;
    int tmp=fast_pow(x,y/2);
    if(y%2)
        return 1LL*tmp*tmp%M*y%M;
    return 1LL*tmp*tmp%M;
}

int hashle(int l, int r){
    if(l==0)
        return h[r];
    return 1LL*(h[r]+M-h[l-1])*fast_pow(inv,l-1)%M;
}

int main(){
    fast;
    test();

    cin>>s>>b>>k;
    for(int i=0;i<s.length();++i)
        if(b[s[i]-'a']=='1')
            bad[i]=1;

    ll carpim=P;
    h[0]=s[0]-'a'+1;
    for(int i=1;i<s.length();++i){
        h[i]=(0LL+h[i-1]+1LL*carpim*(s[i]-'a'+1)%M)%M;
        carpim*=P,carpim%=M;
    }
    for(int i=0;i<s.length();++i)
        cout<<h[i]<<" ";
    cout<<endl;

    inv=fast_pow(P,M-2);    
    for(int i=1;i<s.length();++i)
        bad[i]+=bad[i-1];    
    for(int i=0;i<s.length();++i){
        for(int j=i;j<s.length();++j){
            int kotu= i==0?bad[j]:bad[j]-bad[i-1];
            if(kotu<=k){
                int myhash=hashle(i,j);
                ans[myhash]++;
                // cout<<s.substr(i,j-i+1)<<
            }
        }
    }
    int a=hashle(0,1);
    int b=hashle(2,3);
    dbg(a);
    dbg(b);
    cout<<ans.size();

    return 0;
}