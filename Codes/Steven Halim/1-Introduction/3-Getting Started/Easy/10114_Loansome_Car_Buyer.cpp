#include<semih/competitive.h>

int ay,eskimesayisi;
double pesinat,kredi;
double eskime[105];

int main(){
    test;
    while(cin>>ay>>pesinat>>kredi>>eskimesayisi,ay>=0){
        for(int i=0;i<=ay;++i)
            eskime[i]=-1.0;
        for(int i=0;i<eskimesayisi;++i){
            int a;
            string b;
            cin>>a>>b;
            double yuzde=stod("0"+b);
            eskime[a]=yuzde;
        }
        for(int i=0;i<=ay;++i)
            if(eskime[i]==-1.0)
                eskime[i]=eskime[i-1];
        
        int cnt=0;
        double araba=kredi+pesinat,borc=kredi;
        araba=araba*(1.0-eskime[0]);
        while(araba<borc){
            cnt++;
            borc-=kredi/ay;
            araba=araba*(1.0-eskime[cnt]);
        }
        cout<<cnt<<" month";
        if(cnt!=1) cout<<"s";
        cout<<"\n";
    }
}