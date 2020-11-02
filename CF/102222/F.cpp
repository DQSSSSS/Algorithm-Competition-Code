#include<bits/stdc++.h>
using namespace std;

typedef unsigned int UI;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
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

int f[222][222];
int dist[222][222];
int ans[SZ];
pii a[SZ];

struct edge {
    int u,v,w,id;
}l[SZ];

bool cmp(edge a,edge b) {
    return a.w < b.w;
}

int main() {
    int T = read();
    for(int cc = 1;cc <= T;cc ++) {
        int n = read(),q = read();
        for(int i = 1;i <= n;i ++) a[i] = make_pair(read(),i);
        sort(a+1,a+1+n);
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= n;j ++) {
                f[i][j] = read();
            }
        }

        for(int i = 1;i <= q;i ++) {
            l[i].u = read();
            l[i].v = read();
            l[i].w = read();
            l[i].id = i;
        }

        sort(l+1,l+1+q,cmp);

        for(int i = 1,j = 1;i <= q;i ++) {
            while(j <= n && a[j].first <= l[i].w) {
                int z = a[j].second;
                for(int x = 1;x <= n;x ++) {
                    for(int y = 1;y <= n;y ++) {
                        f[x][y] = min(f[x][y],f[x][z]+f[z][y]);
                    }
                }
                j ++;
            }
            int x = l[i].u;
            int y = l[i].v;
            ans[l[i].id] = f[x][y];
        }

        printf("Case #%d:\n",cc);
        for(int i = 1;i <= q;i ++) printf("%d\n",ans[i]);
    }
}
