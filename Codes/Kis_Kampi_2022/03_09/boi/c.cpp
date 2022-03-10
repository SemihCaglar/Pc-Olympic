#include<semih/competitive.h>

int n;
string s;
const int N=7e2+5;
vi harfler[15];

int next_letter(int ind, char harf){ // indexten sonraki ilk yeri
    vi &ar=harfler[harf-'a'];
    if(ar.empty())
        return -1;
    int tmp=*upper_bound(all(ar),ind);
    if(tmp==n)
        return -1;
    return tmp;
}

int e_cnt(int l, int r){ // l r arasi e sayisi.
    // dbg(l),dbg(r);
    vi &ar=harfler['e'-'a'];
    int sol=lower_bound(all(ar),l)-ar.begin(); // l den sonraki ilk e
    int sag=upper_bound(all(ar),r)-ar.begin(); // sag=sag-1 olmali
    // cerr<<"cdnjcdn\n";
    if(sag-1-sol+1<0)
        return -1;
    return sag-1-sol+1;
}

int dp[N][15];

int f(int ind, int ileri_harf){ // hangi harfe gidip buraya gelmisim?
    // dbg(ind),dbg(ileri_harf);
    if(ind>n)
        return 0;
    
    int &ref=dp[ind][ileri_harf];
    if(ref!=-1)
        return ref;

    int mn=1e7;
    for(char i='a';i<='j';++i){
        if(i=='e')
            continue;
        int next=next_letter(ind,i); // buraya gidicez - 2 harf kullanarak
        if(next==-1){
            continue;
        }
        int np;
        if(ind==0 or ileri_harf==12)
            np=ind;
        else
            np=next_letter(ind, 'a'+ileri_harf); // buraya kadar temizlemisim usta.
        if(np==-1){
            np=ind;   
        }
        int next_e=next_letter(np,'e');
        if(next_e==-1){
            return ref=0;
        }

        if(next<np){ // zaten silmisim buralari, dewam.
            int maybe = f(next,ileri_harf)+2; // atlama 2 harf
            mn=min(mn, maybe);
            continue;
        }

        if(next_e>next){ // silecek e yok. direkt atla.
            int maybe=f(next, 12)+2; // np o olmalı
            mn=min(mn,maybe);
            continue;
        } 
        int h_cnt=next-next_e; // sola gitme sayisi - 1 harf
        int x_cnt=e_cnt(next_e,next); // silme sayisi - 1 harf
        
        int maybe=f(next_e+1,i-'a')+2+h_cnt+x_cnt; // atladim, sola gittim, sildim.
        mn=min(mn,maybe);
    }
    return ref=mn;
}

int main(){
    fast;
    test();

    cin>>n>>s;
    for(int i=0;i<n;++i){
        int harf=s[i]-'a';
        harfler[harf].pb(i);
    }
    for(char i='a';i<='j';++i)
        harfler[i-'a'].pb(n);

    for(int i=0;i<=n+4;++i)
        for(int j=0;j<15;++j)
            dp[i][j]=-1;

    cout<<f(0,s[0]-'a');
    // cout<<f(3,3);
    // cout<<e_cnt(31,33);

    return 0;
}