#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2e5 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

LL S[SZ];

int main() {
    int T = read();
    LL n = 0,base = 1,flag = 0,p = 0;
    while(T --) {
        char s[5];
        scanf("%s",s);
        if(s[0] == 'a') {
            while(p < S[0]) {
                p ++;
                if(base >= 1e18/S[p]) return puts("OVERFLOW!!!"),0;
                base *= S[p];
            }
            n += base;
            if(n >= (1ll<<32)) return puts("OVERFLOW!!!"),0;
        }
        else if(s[0] == 'f') {
            S[++ S[0]] = read();
        }
        else {
            if(p == S[0]) { base /= S[p]; p --; }
            S[0] --;
        }
    }
    cout << n << endl;
}

