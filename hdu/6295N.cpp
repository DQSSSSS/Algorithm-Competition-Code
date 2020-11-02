#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 200010;
const LL INF = 2e18;
const LL mod = 1000000007;
const int Dx[] = {0,1,0,-1};
const int Dy[] = {1,0,-1,0};

LL read()
{
    LL n = 0;
    char a = getchar();
    int flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int n,a[SZ];
vector<int> g[SZ];

int dfs(int u,int fu,int v,int fv) {
    if(a[u] != a[v]) return 0;
    //cout << u << " " << v << endl;
    int ans = 1;
    for(int i = 0,j = 0;i < g[u].size();i ++) {
        int uv = g[u][i];
        if(uv == fu) continue;
        while(j < g[v].size() && a[g[v][j]] < a[uv]) j ++;
        for(int k = j;k < g[v].size();k ++) {
            int vv = g[v][k];
            if(vv == fv) continue;
            if(u == v && k >= i) break;
            if(a[vv] == a[uv])
                ans += dfs(uv,u,vv,v);
            else
            	break;
        }
    }
    return ans;
}

bool cmp(int x,int y) { return a[x] < a[y]; }
int ff[SZ],tt[SZ];

int main() {
    int T = read();
    while(T --) {
        n = read();
        for(int i = 1;i <= n;i ++) a[i] = read(),g[i].clear();
        for(int i = 1;i < n;i ++){
			int u = read(),v = read();
            g[u].push_back(v); g[v].push_back(u);
			ff[i] = u; tt[i] = v;
		}
        for(int i = 1;i <= n;i ++)
            sort(g[i].begin(),g[i].end(),cmp);
		LL ans = 0;
        for(int i = 1;i <= n;i ++)
            ans += dfs(i,0,i,0);
		for(int i = 1;i < n;i ++)
            ans += dfs(ff[i],tt[i],tt[i],ff[i]);
		printf("%lld\n",ans);
	}
	return 0;
}

/**
233
5
1 2 2 2 2
1 2
1 3
1 4
1 5
*/
