#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

int n,m,mp[SZ];

struct haha {
    LL id,c,rst;
}a[SZ];

bool cmp(haha a,haha b) { return a.c < b.c; }

int main() {
    n = read(),m = read();
    for(int i = 1;i <= n;i ++) a[i].rst = read();
    for(int i = 1;i <= n;i ++) a[i].c = read(),a[i].id = i;
    sort(a + 1,a + 1 + n,cmp);

    for(int i = 1;i <= n;i ++) mp[a[i].id] = i;
    int pos = 1;
    while(m --) {
        LL t = read(),d = read();
        LL ans = 0;
        if(pos > n) { puts("0"); continue; }
        int p = mp[t];
        if(a[p].rst >= d) {
            ans = a[p].c * d;
            a[p].rst -= d;
        }
        else {
            ans = a[p].rst * a[p].c;
            d -= a[p].rst;
            a[p].rst = 0;
            while(pos <= n && d) {
                while(pos <= n && a[pos].rst == 0) pos ++;
                if(pos > n) break;
                LL k = min(a[pos].rst,d);
                ans += k * a[pos].c;
                a[pos].rst -= k;
                d -= k;
            }
            if(d) ans = 0;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
