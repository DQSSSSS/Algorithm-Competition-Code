#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1048576 + 10;
const LL INF = 1e18 + 10;
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

LL f[SZ],g[22][SZ],a[22][22],h[SZ];
int n,m;

void dfs(int s,int d,int S,int t) {
    if(d == m) {
        g[s][S] = t;
        return ;
    }
    dfs(s,d+1,S,t);
    dfs(s,d+1,S|(1<<d),t+a[s][d]);
}

char s[SZ];

int main() {
    n = read(),m = read();
    scanf("%s",s+1);
    for(int i = 2;i <= n;i ++) {
        int x = s[i-1] - 'a';
        int y = s[i] - 'a';
        if(x == y) continue;
        a[x][y] ++;
        a[y][x] ++;
    }

    for(int i = 0;i < m;i ++) {
        dfs(i,0,0,0);
    }

    for(int S = 0;S < (1<<m);S ++) {
        LL ans = 0;
        int msk = 1 << m; msk --;
        int SS = S ^ msk;
        for(int p = 0;p < m;p ++) {
            if(S>>p&1) {
                ans += g[p][SS];
            }
        }
        h[S] = ans;
     //   cout << S << " " << ans << endl;
    }

    for(int i = 0;i < (1<<m);i ++) f[i] = 1e18;
    f[0] = 0;
    for(int S = 0;S < (1<<m);S ++) {
        for(int p = 0;p < m;p ++) {
            if(S>>p&1) continue;
           // printf("%d + %d -> %d %lld %lld %lld\n",S,p,S|(1<<p),g[p][S],h[S],f[S]+g[p][S]+h[S]);
            f[S|(1<<p)] = min(f[S|(1<<p)],f[S]+h[S]);
        }
    }
    printf("%lld\n",f[(1<<m)-1]);
}
