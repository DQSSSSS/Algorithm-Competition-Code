#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 5e6 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

vector<int> G[SZ];

double f[SZ],g[SZ];
int rd[SZ],tmp[SZ],d[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read(),m = read();
        for(int i = 1;i <= n;i ++) {
            G[i].clear();
            f[i] = g[i] = 0;
            d[i] = rd[i] = 0;
        }
        for(int i = 1;i <= m;i ++) {
            int x = read(),y = read();
            G[y].push_back(x);
            d[x] ++;
            rd[x] ++;
        }

        queue<int> q;
        for(int i = 1;i <= n;i ++) tmp[i] = rd[i];
        q.push(n);
        while(q.size()) {
            int v = q.front(); q.pop();
            if(v!=n)f[v] += (d[v]+1.0)/d[v];
            for(int u : G[v]) {
                f[u] += f[v] / (double)d[u];
               // printf("%d %d %.f/%.f %.f\n",v,u,f[v],(double)d[u],f[v] / (double)d[u]);
                if(-- tmp[u] == 0) {
                    q.push(u);
                }
            }
        }

        for(int i = 1;i <= n;i ++) tmp[i] = rd[i];
        q.push(n);
        while(q.size()) {
            int v = q.front(); q.pop();
            if(v!=n)g[v] += (d[v]+1.0)/d[v]*(2.0/(d[v]+1.0)*f[v]+1);
            for(int u : G[v]) {
                g[u] += g[v] / d[u] + 2.0/d[u] * f[v];
                if(-- tmp[u] == 0) {
                    q.push(u);
                }
            }
        }
        /*for(int i = 1;i <= n;i ++) printf("%d ",rd[i]); puts("");
        for(int i = 1;i <= n;i ++) printf("%d ",d[i]); puts("");
        for(int i = 1;i <= n;i ++) printf("%.3f ",f[i]); puts("");
        for(int i = 1;i <= n;i ++) printf("%.3f ",g[i]); puts("");
        printf("%f %f\n",f[1],g[1]);*/
        printf("%.2f\n",(g[1]+f[1])/2);
    }
}
