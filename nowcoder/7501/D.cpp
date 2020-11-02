#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 2e6 + 10;
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

int low[SZ],dfn[SZ],n,m;
int num[SZ],ltksz[SZ],cut[SZ],ins[SZ];
int dfs_clock,cnt,ccnt;
vector<int> g2[SZ],g[SZ];
stack<int> S;

void Tarjan(int u,int f) {
    ltksz[cnt] ++;
    num[u] = cnt;
	dfn[u] = low[u] = ++ dfs_clock;
	S.push(u); ins[u] = 1;
	int child = 0;
	for(int i = 0;i < g2[u].size();i ++) {
		int v = g2[u][i];
		if(v == f) continue;
		if(!dfn[v]) {
			child ++;
			Tarjan(v,u);
			low[u] = min(low[u],low[v]);
			if(low[v] >= dfn[u]) {
				ccnt ++;
				cut[u] = 1;
				int x;
				do{
					x = S.top(); S.pop();
					ins[x] = 0;
					g[ccnt + n].push_back(x);
					g[x].push_back(ccnt + n);
				}while(x != v && !S.empty());
				g[ccnt + n].push_back(u);
				g[u].push_back(ccnt + n);
			}
		}
		else if(ins[v]) {
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(f == 0 && child == 1) cut[u] = 0;
}

int main() {
    n = read(),m = read();
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read();
        g2[x].push_back(y);
        g2[y].push_back(x);
    }
    for(int i = 1;i <= n;i ++) {
        if(!dfn[i]) {
            cnt ++;
            Tarjan(i,0);
        }
    }

  //  for(int u = 1;u <= n;u ++) cout << num[u] << " "; puts("");
    for(int u = 1;u <= n;u ++) {
        int id = num[u];
        if(ltksz[id] == 1) {
            printf("%d ",cnt-1);
        } else {
            int t = 0;
            for(int v : g[u]) {
                if(v>n) t ++;
            }
            printf("%d ",cnt+t-1);
        }
    }
}
/*
4 3
1 2
1 3
2 3

6 6
1 2
1 3
2 3
1 6
2 4
3 5
*/
