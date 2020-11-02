#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
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

struct haha {
    int c,h;
}a[SZ];

bool cmpc(haha a,haha b) { return a.c < b.c; }
bool cmph(haha a,haha b) { return a.h > b.h; }

int main() {
    freopen("icecream.in","r",stdin);
    int T = read();
    while(T --) {
        int n = read(),k = read();
        for(int i = 1;i <= n;i ++) a[i].c = read();
        for(int i = 1;i <= n;i ++) a[i].h = read();
        sort(a + 1, a + 1 + n, cmpc);
        int ans1 = a[k].c,r = 0;
        for(int i = 1;i <= n;i ++) if(a[i].c == ans1) r = i;
        sort(a + 1, a + 1 + r, cmph);
        LL ans = 0;
        for(int i = 1;i <= k;i ++) ans += a[i].h;
        printf("%d %lld\n",ans1,ans);
    }
}

