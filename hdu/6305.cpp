#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 2000010;
const int INF = 1000000010;
const int MOD = 1000000007;

LL read() {
	LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0', a = getchar(); }
	if(flag) n = -n;
	return n;
}

int st[SZ][22];
LL inv[SZ];
int a[SZ],n;
int S[SZ],l[SZ],r[SZ];

void build() {
    for(int i = 1;i <= n;i ++) l[i] = r[i] = 0;
	int top = 0;
    for(int i = 1;i <= n;i ++) {
        int k = top;
        while(k && a[S[k]] < a[i]) k --;
        if(k) r[S[k]] = i;
        if(k < top) l[i] = S[k + 1];
        top = k;
        S[++ top] = i;
    }
}

LL ans = 1;
bool vis[SZ];

int dfs(int u) {
    int sz = 1;
    if(l[u]) sz += dfs(l[u]);
    if(r[u]) sz += dfs(r[u]);
    ans = ans * inv[sz] % MOD;
    return sz;
}

LL get_ans() {
    ans = 1;
    for(int i = 1;i <= n;i ++) vis[i] = 0;
    for(int i = 1;i <= n;i ++) vis[l[i]] = vis[r[i]] = 1;
    int rt;
    for(int i = 1;i <= n;i ++) if(!vis[i]) rt = i;
    dfs(rt);
	return ans;
}

int main() {
    inv[1] = 1;
    for(int i = 2;i <= 1e6;i ++) inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
	int T = read();
    while(T --) {
        n = read();
        for(int i = 1;i <= n;i ++) a[i] = read();
        build();
        printf("%lld\n",get_ans() * n % MOD * inv[2] % MOD);
    }
	return 0;
}

