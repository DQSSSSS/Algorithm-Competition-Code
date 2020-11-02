#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
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

struct haha {

    LL value[SZ],setAdd[SZ],belong[SZ],setSize[SZ];

    void work(int x,LL d) {
        value[x] += setAdd[belong[x]];
        setAdd[belong[x]] += d;
        setSize[belong[x]] --;
        belong[x] ++;
        value[x] -= setAdd[belong[x]];
        value[x] -= d * setSize[belong[x]];
        setSize[belong[x]] ++;
    }

    LL ask(int x) {
        return value[x] + setAdd[belong[x]];
    }

    void init(int n) {
        setSize[0] = n;
    }
}data;


int main() {
    int n = read(),m = read();
    data.init(n);
    for(int i = 1;i <= m;i ++) {
        int k = read();
        while(k --) {
            int x = read();
            data.work(x,m-i+1);
        }
    }
    for(int i = 1;i <= n;i ++) {
        printf("%.9f\n",1 + 1.0 * data.ask(i) / m);
    }
}
