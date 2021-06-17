#include<bits/stdc++.h>
#define N 100005
#define inf 1000000009
#define pb push_back
using namespace std;

string s;

int main () {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    cin >> s;
    for(int i = 0; i < s.length() - 1; i++)
        if((s[i] - '0')%2 == 0 and s[i] - '0' < s[s.length() - 1] - '0' ){
            swap(s[i], s[s.length() - 1]);
            break;
        }
    if( (s[s.length() - 1] - '0')%2 == 1 ){//tek sayiysa
        for(int i = s.length() - 2; i >= 0; i--)
            if((s[i] - '0')%2 == 0){
                swap(s[i], s[s.length() - 1]);
                break;
            }
    }
    if( (s[s.length() - 1] - '0')%2 == 1 )
        cout << -1 << "\n";
    else
        cout << s << "\n";
    return 0;
}