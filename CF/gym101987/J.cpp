#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 4e5 + 10;
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

vector<int> g[1010][22];
int f[1010][1010],n,m,c,A,B,a[1010],b[1010],h[1010];

void dfs(int x,int y) {
    if(f[x][y]) return ;
    f[x][y] = 1;
    for(int i = 1;i <= c;i ++) {
        for(int u : g[x][i]) {
            for(int v : g[y][i]) {
                dfs(u,v);
            }
        }
    }
}

int main() {
    n = read(),m = read(),c = read(),A = read(),B = read();
    for(int i = 1;i <= A;i ++) a[i] = read(),h[a[i]] = 1;
    for(int i = 1;i <= B;i ++) b[i] = read();

    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read(),z = read();
        g[x][y].push_back(z);
    }

    for(int i = 1;i <= A;i ++)
        for(int j = 0;j < n;j ++)
            if(!h[j])
                dfs(a[i],j);

    for(int i = 1;i <= B;i ++)
        for(int j = 1;j <= B;j ++)
            if(f[b[i]][b[j]])
                return puts("YES"),0;
    return puts("NO"),0;
}
/**
5 6 2 1 1
0
4
0 1 1
1 1 2
2 2 3
2 2 1
3 1 4
4 1 4

5 4 2 2 2
1 3
2 4
0 2 1
1 1 2
3 2 3
3 1 4

*/
