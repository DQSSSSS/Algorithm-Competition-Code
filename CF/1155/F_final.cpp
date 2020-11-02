#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int edges1[15][15][17010];
vector<int> nodes[17010];
vector<pii> G[22];

bool vis[17010];
int f[17010],g[15][15][17010];
int to[15][17010],n,m,trans[17010];

void print(int S) {
    for(int i = 0;i < n;i ++)
        if(S >> i & 1)
            printf("%d,",i+1);

}

void dfs(int S) {
    if(vis[S]) return ;
    vis[S] = 1;
    int ans = 1e9,e1 = 0,e2 = 0;
    for(int S1 = (S-1)&S; S1 > 0 ; S1 = (S1-1)&S) {
        int S2 = S ^ S1;
        dfs(S1);
        for(int i = 0;i < n;i ++) {
            if((S2 >> i & 1) == 0) continue;
            if(!to[i][S1]) continue;
            for(int j = 0;j < n;j ++) {
                if((S2 >> j & 1) == 0) continue;
                if(!to[j][S1]) continue;
                if(!g[i][j][S2]) continue;

                int tmp = f[S1] + g[i][j][S2] + 2;
                if(tmp < ans) {
                    ans = tmp;
                    trans[S] = S1;
                    e1 = i;
                    e2 = j;
                }
            }
        }
    }

    for(int i = 0;i < n;i ++) {
        if(S >> i & 1) {
            int S1 = S ^ (1<<i);
            int t1 = 0,t2 = 0;
            for(pii p : G[i]) {
                int v = p.first;
                if(S1 >> v & 1) {
                    if(!t1) t1 = p.second;
                    else t2 = p.second;
                }
            }
            if(t2 == 0) continue;
            int tmp = f[S1] + 2;
            if(tmp < ans)
                ans = tmp,e1 = i,e2 = i,trans[S] = S1;
        }
    }

    f[S] = ans;
    nodes[S].push_back(e1);
    nodes[S].push_back(e2);
}

int a[SZ],b[SZ];
int pre[15][15][17010];

int main() {
    n = read(),m = read();
    for(int i = 1;i <= m;i ++) {
        int x = read() - 1,y = read() - 1;
        g[x][y][(1<<x)|(1<<y)] = 1;
        g[y][x][(1<<x)|(1<<y)] = 1;
        edges1[x][y][(1<<x)|(1<<y)] = i;
        edges1[y][x][(1<<x)|(1<<y)] = i;
        G[x].push_back(make_pair(y,i));
        G[y].push_back(make_pair(x,i));
        a[i] = x; b[i] = y;
    }

    vis[0] = 1;
    for(int i = 0;i < n;i ++) {
        f[1<<i] = 0,vis[1<<i] = 1;
        for(int S = 0;S < (1<<n);S ++) {
            for(pii p : G[i]) {
                if(S >> p.first & 1) {
                    to[i][S] = p.second;
                    break;
                }
            }
        }
    }

    for(int S = 0;S < (1<<n);S ++) {
        for(int i = 0;i < n;i ++) {
            if((S >> i & 1) == 0) continue;
            for(int j = 0;j < n;j ++) {
                if((S >> j & 1) == 0) continue;
                if(!g[i][j][S]) continue;

                for(pii p : G[j]) {
                    int x = p.first;
                    if(S >> x & 1) continue;
                    if(x == i) continue;

                    if(!g[i][x][S^(1<<x)]) {
                        g[i][x][S^(1<<x)] = g[i][j][S] + 1;
                        pre[i][x][S^(1<<x)] = j;
                        edges1[i][x][S^(1<<x)] = p.second;
                    }
                }

            }
        }
    }

    dfs((1<<n)-1);

    printf("%d\n",f[(1<<n)-1]);
    int S = (1<<n)-1;
    while(__builtin_popcount(S) > 1) {
        int S2 = S ^ trans[S],S1 = trans[S];
        int x = nodes[S][0];
        int y = nodes[S][1];
        if(x != y) {
            printf("%d %d\n",a[to[x][S1]]+1,b[to[x][S1]]+1);
            printf("%d %d\n",a[to[y][S1]]+1,b[to[y][S1]]+1);
            while(__builtin_popcount(S2) >= 2) {
                int v = edges1[x][y][S2];
                printf("%d %d\n",a[v]+1,b[v]+1);
                int p = pre[x][y][S2];
                S2 ^= 1 << y; y = p;
            }
            S = S1;
        }
        else {
            int t = 0;
            for(pii p : G[x]) {
                if(S1 >> p.first & 1) {
                    printf("%d %d\n",a[p.second]+1,b[p.second]+1);
                    if(++t == 2) break;
                }
            }
            S = S1;
        }
    }
}
