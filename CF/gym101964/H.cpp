#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-12;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int ff[SZ],tt[SZ],a[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read(),m = read();
        for(int i = 1;i <= m;i ++)
            ff[i] = read(),tt[i] = read();
        int t;
        while(1) {
            for(int i = 1;i <= n;i ++) a[i] = rand() % 2;
            t = 0;
            for(int i = 1;i <= m;i ++) {
                int x = ff[i],y = tt[i];
                if(a[x] && !a[y]) t ++;
            }
            if(t >= m / 4 + 1) break;
        }
        printf("%d\n",t);
        for(int i = 1;i <= m;i ++) {
            int x = ff[i],y = tt[i];
            if(a[x] && !a[y]) printf("%d ",i);
        }
        puts("");
    }
}
