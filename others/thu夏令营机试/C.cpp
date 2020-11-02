#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1000010;
const LL INF = 1e18 + 10;
const LL mod = 998244353;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

struct edge {
    int x,y,z;
}E[SZ];

vector<int> G[SZ];
int col[SZ],mat[22][22];

void dfs(int u,int c) {
    col[u] = c;
    for(int v : G[u]) {
        if(!col[v]) {
            dfs(v,c);
        }
    }
}

int g[(1 << 15)+10];
int f[(1 << 15)+10];

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b & 1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    int n = read(),m = read();

    if(m == n - 1) {
        for(int i = 1;i <= m;i ++) {
            int x,y,z;
            x = read(),y = read(),z = read();
            G[x].push_back(y);
            G[y].push_back(x);
        }
        int tot = 0;
        for(int i = 1;i <= n;i ++) {
            if(!col[i]) {
                tot ++;
                dfs(i,tot);
            }
        }
        if(tot == 1) puts("1");
        else puts("0");
        return 0;
    }

    for(int i = 1;i <= m;i ++) {
        int x,y,z;
        x = read(),y = read(),z = read();
        E[i] = (edge){x,y,z};
        if(z == 0) {
            G[x].push_back(y);
            G[y].push_back(x);
        }
    }
    int tot = 0;
    for(int i = 1;i <= n;i ++) {
        if(!col[i]) {
            tot ++;
            dfs(i,tot);
        }
    }

 //   for(int i = 1;i <= n;i ++) cout << col[i] << " "; puts("");

    LL w = 1;
    for(int i = 1;i <= m;i ++) {
        if(E[i].z == 1) {
            if(col[E[i].x] == col[E[i].y])
                w = w * 2 % mod;
            else {
                mat[col[E[i].x]-1][col[E[i].y]-1] ++;
                mat[col[E[i].y]-1][col[E[i].x]-1] ++;
            }
        }
    }

    for(int S = 0;S < (1<< tot);S ++) {
        vector<int> tmp;
        for(int i = 0;i < tot;i ++)
            if(S >> i & 1)
                tmp.push_back(i);

        for(int i = 0;i < tmp.size();i ++) {
            for(int j = i + 1;j < tmp.size();j ++) {
                int x = tmp[i];
                int y = tmp[j];
                if(mat[x][y]) {
                    g[S] += mat[x][y];
                }
            }
        }
        g[S] = ksm(2,g[S]);
    }

    f[0] = 0;
    for(int S = 0;S < (1 << tot);S ++) {
        int low = 0;
        for(int i = 0;i < tot;i ++) {
            if(S >> i & 1) low = 1 << i;
        }
        f[S] = g[S];
        for(int S1 = (S - 1) & S;S1;S1 = (S1 - 1) & S) {
            if(S1 == S) continue;
            if((S1 & low)) {
                if(f[S1]) {
                    f[S] -= 1ll * f[S1] * g[S1 ^ S] % mod;
                    if(f[S] >= mod) f[S] -= mod;
                    if(f[S] < 0) f[S] += mod;
                }
            }
            else {
                break;
            }
        }
    }
    if(f[(1 << tot) - 1]<0) f[(1 << tot) - 1] += mod;

   /* cout << tot << " " << w << endl;
    for(int S = 0;S < (1<<tot);S ++) {
        printf("%lld ",g[S]);
    }
    puts("");
    for(int S = 0;S < (1<<tot);S ++) {
        printf("%lld ",f[S]);
    }
    puts("");
*/
    printf("%lld\n",f[(1 << tot) - 1] * w % mod);
    return 0;
}

