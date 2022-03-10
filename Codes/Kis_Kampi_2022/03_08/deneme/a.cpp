#include<semih/competitive.h>

typedef unsigned long long int ulli;

ulli a,b;

// ulli f(int x, int kac){ // x. basamaktayiz. <=k olacak. kac: rakam kactan kucuk olmali?
//     // ulli &ref=dp[x][kac];
//     // if(ref)
//     //     return ref;
//     // if(x==(int)tmp.size()){
//     //     return (ulli) 1;
//     // }
//     // ulli basamak=tmp[x]-'0';
//     // if(state==true)
//     //     return ref=10*f(x+1, true);
//     // else
//     //     return ref=basamak*f(x+1, true)+f(x+1, false);

// }

ulli fp[15];

ulli f(string x){
    string tmp;
    ulli sum=0;
    for(auto i: x)
        tmp+=" ";
    for(int i=0;i<=(x.size()-1)/2;i++){
        ulli basamak=x[i]-'0';
        sum+=(i==0?basamak-1:basamak)*fp[ ( x.size()-1-2*i ) / 2];
        tmp[i]=tmp[x.size()-1-i]='0'+basamak;
    }
    if(tmp<=x)
        sum++;
    return sum;
}

ulli g(string x){
    ulli sum=0;
    string tmp="";
    for(int i=1;i<x.size();++i){
        tmp+="9";
        sum+=f(tmp);
    }
    sum+=f(x);
    return sum;
}

int main(){
    fast;
    test();

    ulli carpim=1;
    for(int i=0;i<15;++i)
        fp[i]=carpim, carpim*=10;

    cin>>a>>b;
    ulli pal=g(to_string(b));
    dbg(pal);


    pal-=g(to_string(a-1));
    
    ulli tamami=b-a+1;

    cout<<tamami<<" "<<pal<<" "<<tamami-pal<<"\n";

    dbg(f(to_string(32)));

    return 0;
}