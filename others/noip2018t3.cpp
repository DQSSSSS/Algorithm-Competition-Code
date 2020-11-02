#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 100010;
const int INF = 1e9 + 10;
const int mod = 7340033;
const LD eps = 1e-8;
const LD PI = acos(-1);

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
	int t,d;
};

vector<edge> g[SZ];

int f[SZ],mx[SZ],tmp[SZ],use[SZ];

int fa[SZ];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

void dfs(int u,int Fa,int mid) {
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i].t;
        if(v == Fa) continue;
        dfs(v,u,mid);
        f[u] += f[v];
    }
    int top = 0;
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i].t;
        if(v == Fa) continue;
        int d = mx[v] + g[u][i].d;
        if(d >= mid) { f[u] ++; continue; }
        tmp[++ top] = d; use[top] = 0;
    }
    sort(tmp + 1,tmp + 1 + top);
    for(int i = 1;i <= top + 1;i ++) fa[i] = i;
    for(int i = 1;i <= top;i ++) {
    	if(i != fa[i]) continue;
    	int r = lower_bound(tmp + i + 1,tmp + top + 1,mid - tmp[i]) - tmp;
    	r = find(r);
    	if(r == top + 1) continue;
    	int ff = find(r + 1);
    	f[u] ++;
    	fa[r] = ff;
    	int ii = find(i + 1);
    	fa[i] = ii;
    }
    for(int i = top;i >= 1;i --) 
        if(fa[i] == i) {
            mx[u] = tmp[i];
            break;
        }
	//cout << u << endl;
	//for(int i = 1;i <= top;i ++) cout << tmp[i] << " "; puts("");
	//for(int i = 1;i <= top;i ++) cout << use[i] << " "; puts("");
}

int n,m;

bool check(const int &mid) {
	for(int i = 1;i <= n;i ++) f[i] = 0,mx[i] = 0;
	dfs(1,0,mid);
	//for(int i = 1;i <= n;i ++) cout << f[i] << " "; puts("");
	//for(int i = 1;i <= n;i ++) cout << mx[i] << " "; puts("");
	return f[1] >= m;
}

int main() {
	//freopen("track18.in","r",stdin);
	n = read(),m = read();
	for(int i = 1;i < n;i ++) {
		int x = read(),y = read(),z = read();
		g[x].push_back((edge){y,z});
		g[y].push_back((edge){x,z});
	}
//	cout << check(17) << endl;
	int l = 0,r = 500000000 + 1;
	while(r - l > 1) {
		int mid = l + r >> 1;
		if(check(mid)) l = mid;
		else r = mid;
	}
	printf("%d\n",l);
	return 0;
}
/**
5 2
1 2 2
1 3 2
1 4 3
1 5 2

*/
