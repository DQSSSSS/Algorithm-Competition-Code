#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 5e4 + 10;
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

int f[511][511];

int main() {
    freopen("F.in","r",stdin);
    freopen("std.out","w",stdout);

    int T = read();
    while(T --) {
        int n = read(),m = read(),Q = read();
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= n;j ++){
                f[i][j] = 0;
            }
            f[i][i] = 1;
        }
        for(int i = 1;i <= m;i ++) {
            int x = read(),y = read();
            f[x][y] = 1;
        }
        for(int k = 1;k <= n;k ++) {
            for(int i = 1;i <= n;i ++) {
                for(int j = 1;j <= n;j ++) {
                    if(f[i][k] && f[k][j])
                        f[i][j] = 1;
                }
            }
        }
        vector<int> g;
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= n;j ++) {
                if(f[i][j]) g.push_back(i^j);
            }
        }
        sort(g.begin(),g.end());
        reverse(g.begin(),g.end());
        while(Q --) {
            int k = read(),ans = 0;
            if(k<=g.size()) ans = g[k-1];
            printf("%d\n",ans);
        }
    }
}
