#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
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

struct hehe {
	int x,y,u,v;
}S[SZ];
int top,fa[SZ],sz[SZ];

int find(int x) { return x == fa[x] ? x : find(fa[x]); }

LL work(int u,bool c,int L,int R) {
	LL ans = 0;
	for(int j = 0;j < g[u].size();j ++){
		if(g[u][j] < L || g[u][j] > R) continue;
		int x = find(u),y = find(g[u][j]);
		if(x != y) {
			if(sz[x] > sz[y]) swap(x,y);
			fa[x] = y;
			ans += 1ll * sz[x] * sz[y];
			sz[y] += sz[x];
			if(c) S[++ top] = (hehe){x,y,u,g[u][j]};
		}
	}
	return ans;
}

int pr[SZ],nx[SZ];

void del(int x) {
	pr[nx[x]] = pr[x];
	nx[pr[x]] = nx[x];
}

struct haha {
	int l,r,id;
}ask[SZ];

int id[SZ],lst[SZ],B,du[SZ];

bool cmp(haha a,haha b) {
	if(id[a.l] == id[b.l]) return a.r < b.r;
	return a.l < b.l;
}

int ff[SZ],tt[SZ];
LL Ans[SZ];
/*
namespace bl {
	LL Ans[SZ];
	int fa[SZ],sz[SZ];
	int find(int x) { return x == fa[x] ? x : find(fa[x]); }
	
	void baoli(int l,int r,int id) {
		for(int i = l;i <= r;i ++) fa[i] = i,sz[i] = 1;
		LL ans = 0;
		for(int u = l;u <= r;u ++) {
			for(int i = 0;i < g[u].size();i ++) {
				int v = g[u][i];
				if(l <= v && v <= r) {
					int x = find(u),y = find(v);
					if(x != y) {
						fa[x] = y;
						ans += sz[x] * sz[y];
						sz[y] += sz[x];
					}
				}
			}
		}
		Ans[id] = ans;
	}
}
*/
int main() {
	//freopen("1629.in","r",stdin);
	int T = read();
	while(T --) {
		//cout << T << "---" << endl;
		top = 0;
		int n = read(),m = read(),q = read();
		B = sqrt(2 * m / (log2(n + 1)));
		for(int i = 1;i <= n;i ++) du[i] = 0,g[i].clear();
		for(int i = 1;i <= m;i ++) {
			ff[i] = read(),tt[i] = read();
			du[ff[i]] ++;
			du[tt[i]] ++;
			g[ff[i]].push_back(tt[i]);
			g[tt[i]].push_back(ff[i]);
		}
		
		for(int i = 0;i <= n;i ++) nx[i] = i + 1; nx[n] = n + 1;
		for(int i = 0;i <= n;i ++) pr[nx[i]] = i; pr[1] = -1; pr[0] = 0;
		
		for(int i = 1,s = 0,p = 1;i <= n;i ++) {
			if(!du[i]) del(i);
			if(s / B != (s + du[i]) / B) p ++;
			id[i] = p; s += du[i];
			lst[p] = i;
		}
		/*
		for(int i = 0;i <= n;i ++) cout << nx[i] << " "; puts("");
		for(int i = 0;i <= n;i ++) cout << pr[i] << " "; puts("");
		for(int i = 0;i <= n;i ++) cout << i << " "; puts("");
		for(int i = 0;i <= n;i ++) cout << id[i] << " "; puts("");
		for(int i = 0;i <= n;i ++) cout << lst[i] << " "; puts("");
		cout << B << endl;	
		*/
		int cntq = 0;
		for(int i = 1;i <= q;i ++) {
			int l = read(),r = read();
			
			//bl :: baoli(l,r,i);
			
			if(id[l] == id[r]) {
				LL ans = 0;
				for(int j = nx[l-1];j && j <= r;j = nx[j]) fa[j] = j,sz[j] = 1;
				for(int u = nx[l-1];u && u <= r;u = nx[u]) {
					ans += work(u,0,l,r);
				}
				Ans[i] = ans;
			}
			else {
				cntq ++;
				ask[cntq].l = l; ask[cntq].r = r; ask[cntq].id = i;
			}
		}
		sort(ask + 1,ask + 1 + cntq,cmp);

		//for(int i = 1;i <= cntq;i ++) cout << ask[i].l << " " << ask[i].r << " " << ask[i].id << endl;
		for(int kk = 1,i;kk <= cntq;kk = i) {
			for(int j = nx[0];j && j <= n;j = nx[j]) fa[j] = j,sz[j] = 1;
			int r = lst[id[ask[kk].l]],l = nx[r];
			//cout << l << " -- " << r << endl;
			LL ans = 0;
			top = 0;
			for(i = kk;i <= cntq && id[ask[i].l] == id[ask[kk].l];i ++) {
				while(nx[r] <= ask[i].r) {
					r = nx[r];
					ans += work(r,0,l,r);
					//cout << "1 : " << r << endl;
				}
				while(pr[l] >= ask[i].l) {
					l = pr[l];
					ans += work(l,1,l,r);
				}
				//cout << l << " " << r << " " << ask[i].id << " " << ans << endl;				
				Ans[ask[i].id] = ans;
				while(l != nx[lst[id[ask[kk].l]]]) {
					while(top) {
						int x = S[top].x,y = S[top].y;
						if(S[top].u != l && S[top].v != l) break;
						if(sz[x] > sz[y]) swap(x,y);
						sz[y] -= sz[x];
						ans -= 1ll * sz[x] * sz[y];
						fa[y] = y; fa[x] = x;
						top --;
					}
					l = nx[l];
				}
			//	cout << l << " " << r << " " << ans << endl;
			}
		}
		for(int i = 1;i <= q;i ++) {
			printf("%lld\n",Ans[i]);
			//printf("%lld %lld\n",Ans[i],bl::Ans[i]);			
			//if(Ans[i] != bl::Ans[i]) assert(0);
		}
	}
	return 0;
}	
/***
10
10 10 10
6 9
6 3
1 2
6 3
2 10
7 3
8 4
3 7
1 6
3 6

10 10
6 7
3 4
1 6
7 9
4 7
2 10
4 8
7 9
5 8
*/
