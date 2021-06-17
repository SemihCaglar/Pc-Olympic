#include<bits/stdc++.h>
using namespace std;
long long a1,a2,b1,b2;

int main(){
    cin>>a1>>b1>>a2>>b2;
    long long fark;
    if(a1>a2){
        fark = a1 - a2;
        if (b1 < 0)
            b1 *= -1, b2 *= -1; // b1/x=b2/fark-x
        double result = b1 * fark / (b1 + b2 + 0.0);
        printf("%8lf",a1-result);
    }
    else
    {
        fark = a2 - a1;
        if (b1 < 0)
            b1 *= -1, b2 *= -1; // b1/x=b2/fark-x
        double result = b1 * fark / (b1 + b2 + 0.0);
        printf("%8lf",a1+result);
    }

}