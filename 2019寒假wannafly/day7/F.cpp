#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 5000010;
const int mod = 998244353;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}

int tree[2][SZ],lsh[SZ];

void add(int x,int d,int id) {
    for(int i = x;i <= lsh[0];i += i & -i) tree[id][i] += d;
}

int ask(int x,int id) {
    int ans = 0;
    for(int i = x;i > 0;i -= i & -i) ans += tree[id][i];
    return ans;
}

LL f[33],b[SZ];

bool check(int len,int m) {
    int g[33] = {0};
    for(int i = 1;i <= m;i ++) {
        for(int j = 0;j <= len;j ++)
            if(i >> j & 1)
                g[j] ++;
    }
    for(int i = 0;i <= len;i ++) printf("%4d",g[i]); puts("");
    for(int i = 0;i <= len;i ++) assert(g[i] == f[i]);
}

struct haha {
    int val,id;
}a[SZ];

bool cmpval(haha a,haha b) { return a.val < b.val; }
bool cmpid(haha a,haha b) { return a.id < b.id; }


LL baoli(int n,int m) {
    LL ans = 0;
    for(int k = 1;k <= m;k ++) {
        lsh[0] = 0;
        for(int i = 1;i <= n;i ++) {
            lsh[++ lsh[0]] = b[i] ^ k;
        }
        sort(lsh + 1,lsh + 1 + lsh[0]);
        lsh[0] = unique(lsh + 1,lsh + 1 + lsh[0]) - lsh - 1;

        for(int i = 1;i <= n;i ++) {
            int pos = lower_bound(lsh + 1,lsh + 1 + lsh[0],b[i] ^ k) - lsh;
            (ans += i - 1 - ask(pos,0)) %= mod;
            add(pos,1,0);
        }
        for(int i = 1;i <= n;i ++) {
            int pos = lower_bound(lsh + 1,lsh + 1 + lsh[0],b[i] ^ k) - lsh;
            add(pos,-1,0);
        }
    }
    return ans;
}

int tmp[SZ];

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++)
        b[i] = read();

    lsh[0] = 0;
    for(int i = 1;i <= n;i ++) {
            lsh[++ lsh[0]] = b[i];
    }
    sort(lsh + 1,lsh + 1 + lsh[0]);
    lsh[0] = unique(lsh + 1,lsh + 1 + lsh[0]) - lsh - 1;

    int len = 0;
    while((1 << len) <= m) len ++; len --;
    for(int i = len,S = 0;i >= 0;i --) {
        if(m >> i & 1) {
            for(int j = i - 1;j >= 0;j --)
                f[j] += 1 << (i - 1);
            S ^= 1 << i;
            f[i] += (m ^ S) + 1;
        }
    }

    for(int r = 1;r <= n;r ++) tmp[r] = lower_bound(lsh + 1,lsh + 1 + lsh[0],b[r]) - lsh;
    LL ans = 0;
    for(int k = 29;k >= 0;k --) {
        for(int i = 1;i <= n;i ++) a[i] = (haha){b[i] >> (k+1),i};
        stable_sort(a + 1,a + 1 + n,cmpval);
        for(int r = 1,l = 1;r <= n;r ++) {
            if(r == n || a[r + 1].val != a[r].val) {

                int zero = 0,one = 0;
                for(int i = l;i <= r;i ++) {
                    if(b[a[i].id] >> k & 1) one ++;
                    else zero ++;
                }
                if(!one || !zero) { l = r + 1; continue; }
                int prenum[2] = {0};
                for(int i = l;i <= r;i ++) {
                    int id = a[i].id;
                    int pos = tmp[id];
                    int d = b[id] >> k & 1,x = 0;
                    if(prenum[d^1]) x = ask(pos,d ^ 1);
                    if(!d) (ans += 1ll * (m - f[k]) * (prenum[d^1] - x) % mod) %= mod;
                    else (ans += 1ll * f[k] * x % mod) %= mod;
                    prenum[d] ++;
                    add(pos,1,d);
                }
                for(int i = l;i <= r;i ++) {
                    int id = a[i].id,d = b[id] >> k & 1;
                    int pos = tmp[id];
                    add(pos,-1,d);
                }
                l = r + 1;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}

