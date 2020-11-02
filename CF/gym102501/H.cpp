#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 3000010;
const int INF = 1e9 + 10;
const int mod = 1e9+7;
const LD eps = 1e-8;
LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int f[SZ];

LL getnx(LL s) {
    return (s+(s>>20)+12345)%(1ll<<40);
}

int main() {
    LL s = 1611516670,si = 0;
    LL h = 1611516670,hi = 0;
    do {
        s = getnx(s); si ++;
        h = getnx(h); hi ++;
        h = getnx(h); hi ++;
    }while(s != h);
    LL t = 1611516670,ti = 0;
    while(s != t) {
        ti ++;
        s = getnx(s);
        t = getnx(t);
    }
    LL start = ti,now = t,len = 1;
    for(LL x = getnx(t);now != x;len ++) {
        x = getnx(x);
    }
    cout << start << " " << len << endl;

    //LL start = 350125310,len = 182129209;

}
