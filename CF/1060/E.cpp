#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 400010;
const int INF = 1e9 + 10;
const int mod = 10007;
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

vector<int> g[SZ];

LL sz[SZ][2],tsz[SZ];
int fa[SZ],deep[SZ];

void dfs(int u,int f) {
	deep[u] = deep[f] + 1;
	bool c = deep[u] & 1;
	sz[u][c] = 1;
	tsz[u] = 1;
	fa[u] = f;
	for(int i = 0;i < g[u].size();i ++) {
		int v = g[u][i];
		if(v == f) continue;
		dfs(v,u);
		tsz[u] += tsz[v];
		sz[u][c] += sz[v][c];
		sz[u][c ^ 1] += sz[v][c ^ 1];
	}
}

LL a[SZ];

int main() {
	//freopen("E.in","r",stdin);
	//freopen("E.out","w",stdout);
	int n = read();
	for(int i = 1;i < n;i ++) {
		int x = read(),y = read();
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	LL ans = 0,ans2 = 0;
	for(int u = 1;u <= n;u ++) {
		int len = g[u].size();
		bool c = deep[u] & 1;
		LL s1 = 0,s2 = 0;
		for(int i = 0;i < len;i ++) {
			int v = g[u][i];
			if(v == fa[u]) {
				ans += max(0ll,(sz[1][c ^ 1] - sz[u][c ^ 1]));
				ans2 += (n - tsz[u]) * s1;
				ans2 += (sz[1][c ^ 1] - sz[u][c ^ 1]) * s2;
				s1 += sz[1][c ^ 1] - sz[u][c ^ 1];
				s2 += n - tsz[u];
			}
			else {
				ans += (sz[v][c ^ 1]);
				ans2 += (tsz[v]) * s1;
				ans2 += sz[v][c ^ 1] * s2;
				s1 += sz[v][c ^ 1];
				s2 += tsz[v];
			}
		}
	//	cout << u << " " << ans2 <<endl;
//		ans2 += s;
	}
	//cout << ans << " " << ans2<< endl;
	cout << ans / 2 + ans2 / 2 << endl;
	return 0;
}
/**
10
2 3
3 9
6 3
9 8
9 10
4 8
3 1
3 5
7 1

67

5
1 2
2 3
1 4
4 5

5
1 2
2 3
3 4
4 5
*/
