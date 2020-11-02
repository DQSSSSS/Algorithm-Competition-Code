#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 6e6 + 10;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

char f[1<<26];
int G[33];

int dfs(int S) {
    if(f[S] != -1) return f[S];
    int x;
    for(int i = 0;;i ++) if(S>>i&1) { x=i; break; }
    int ans = max(dfs(S^(1<<x)),1+dfs(S&G[x]));
    return f[S] = ans;
}

int main() {
    int n = read(),m = read();
    for(int i = 0;i < n;i ++) {
        G[i] = 1<<n; G[i] --;
        G[i] ^= 1<<i;
    }
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read();
        G[x] ^= 1<<y;
        G[y] ^= 1<<x;
    }
    memset(f,-1,sizeof f);
    f[0] = 0;
    int ans = 0;
    for(int i = 0;i < (1<<n);i ++) {
        ans += dfs(i);
    }
    cout << ans << endl;
}
