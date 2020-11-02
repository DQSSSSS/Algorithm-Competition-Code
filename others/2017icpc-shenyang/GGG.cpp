#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200010;
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

namespace SA {

	int sa[SZ * 2],Rank[SZ * 2],len;

	bool cmp(int *y,int a,int b,int k)
	{
		int a1 = y[a],b1 = y[b];
		int a2 = a + k >= len ? -1 : y[a + k];
		int b2 = b + k >= len ? -1 : y[b + k];
		return a1 == b1 && a2 == b2;
	}

	int t1[SZ * 2],t2[SZ * 2],cc[SZ * 2];

	void get_sa(const string &s)
	{
		len = s.length();
		int *x = t1,*y = t2,m = 433;
		for(int i = 0;i < m;i ++) cc[i] = 0;
		for(int i = 0;i < len;i ++) ++ cc[x[i] = s[i]];
		for(int i = 1;i < m;i ++) cc[i] += cc[i - 1];
		for(int i = len - 1;~i;i --) sa[-- cc[x[i]]] = i;
		for(int k = 1;k < len;k <<= 1)
		{
			int p = 0;
			for(int i = len - k;i < len;i ++)  y[p ++] = i;
			for(int i = 0;i < len;i ++) if(sa[i] >= k) y[p ++] = sa[i] - k;
			for(int i = 0;i < m;i ++) cc[i] = 0;
			for(int i = 0;i < len;i ++) ++ cc[x[y[i]]];
			for(int i = 1;i < m;i ++) cc[i] += cc[i - 1];
			for(int i = len - 1;~i;i --) sa[-- cc[x[y[i]]]] = y[i];
			swap(x,y); m = 1; x[sa[0]] = 0;

			for(int i = 1;i < len;i ++)
				x[sa[i]] = cmp(y,sa[i - 1],sa[i],k) ? m - 1 : m ++;
			if(m >= len) break;
		}
		for(int i = 0;i < len;i ++) Rank[sa[i]] = i;
	}
}

int n,to[SZ],rd[SZ];
bool isring[SZ];
int st[SZ],fa[SZ];
char a[SZ];
bool vis[SZ],use[SZ];
string s;
vector<int> maxStrs;
int ringlen[SZ],ansid[SZ],dist[SZ];
vector<int> nownode,g[SZ],ltk[SZ];

void dfs(int u) {
	vis[u] = 1;
	nownode.push_back(u);
    for(int i = 0;i < ltk[u].size();i ++) {
        int v = ltk[u][i];
        if(vis[v]) continue;
        dfs(v);
    }
}

namespace Tarjan {
	int dfn[SZ],low[SZ],dfs_clock = 0,scccnt = 0,sccnum[SZ];
    vector<int> g[SZ];
	stack<int> S;
	void tarjan(int u) {
		S.push(u);
        low[u] = dfn[u] = ++ dfs_clock;
        int v = to[u];
        if(!dfn[v]) {
			tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(!sccnum[v]) {
            low[u] = min(low[u],dfn[v]);
        }
        if(low[u] == dfn[u]) {
            scccnt ++;
            while(233) {
            	int x = S.top(); S.pop();
                sccnum[x] = scccnt;
                g[scccnt].push_back(x);
                if(x == u) break;
            }
        }
	}
	void find_ring() {
		for(int i = 0;i < nownode.size();i ++)
			if(!dfn[nownode[i]])
				tarjan(nownode[i]);
		bool flag = 0;
		for(int i = 1;i <= scccnt;i ++) {
			if(g[i].size() > 1) {
				for(int j = 0;j < g[i].size();j ++)
					isring[g[i][j]] = 1;
			}
		}
		for(int i = 1;i <= n;i ++)
			if(to[i] == i) isring[i] = 1;
	}
	void tarjan_init() {
		for(int i = 1;i <= scccnt;i ++) sccnum[i] = 0,g[i].clear();
		for(int i = 0;i < nownode.size();i ++) {
			int u = nownode[i];
			dfn[u] = low[u] = 0;
		}
		dfs_clock = scccnt = 0;
	}
}

bool cmp_str_smaller(int x,int y) {
    int nowx = st[x],nowy = st[y];
    if(a[nowx] != a[nowy]) return a[nowx] < a[nowy];
    while(nowx != x && nowy != y) {
	    nowx = fa[nowx]; nowy = fa[nowy];
        if(a[nowx] != a[nowy]) return a[nowx] < a[nowy];
    }
    if(nowx == x && nowy == y) return false;
    if(nowx == x) return true;
    return false;
}
///小则是1 大则是0 相等为-1 前者为后者前缀为-2, 否则-3
int cmp_str_smaller2(int x,int y) {
    int nowx = st[x],nowy = st[y];
    if(a[nowx] != a[nowy]) return a[nowx] < a[nowy];
    while(nowx != x && nowy != y) {
	    nowx = fa[nowx]; nowy = fa[nowy];
        if(a[nowx] != a[nowy]) return a[nowx] < a[nowy];
    }
    if(nowx == x && nowy == y) return -1;
    if(nowx == x) return -2;
    return -3;
}

int deep[SZ];

void dfs2(int u,int ff) {
    st[u] = u;
    fa[u] = ff;
    deep[u] = deep[ff] + 1;
    for(int i = 0;i < g[u].size();i ++) {
    	int v = g[u][i];
        dfs2(v,u);
        if(cmp_str_smaller(u,v))
        	st[u] = st[v];
    }
   // cout << u << " " << st[u]<< endl;
}


void get_str_ring(int u,int ed) {
    s += a[u];
    if(to[u] == ed) { return ; }
    get_str_ring(to[u],ed);
}

void work_init() {
	Tarjan :: tarjan_init();
	nownode.clear();
	maxStrs.clear();
	s = "";
}

void work(int u,int id) {
	work_init();
   	dfs(u);
    Tarjan :: find_ring();
    int rings = -1;
    for(int i = 0;i < nownode.size();i ++) {
    	int x = nownode[i];
        if(isring[x]) {
			rings = x;
            get_str_ring(x,x);
            break;
        }
    }
    int len = s.length(),ringlen = len;
    for(int i = 0;i < len;i ++) s += s[i];
    SA :: get_sa(s);
    //cout << rings << endl;
    for(int i = 0;i < nownode.size();i ++) {
 		int x = nownode[i];
        if(!isring[x] && isring[to[x]]) {
     //   	cout << x << endl;
     		deep[to[x]] = 0;
			dfs2(x,to[x]);
			maxStrs.push_back(x);
	//		puts("");
        }
    }
    bool allsame = 1;
	for(int i = 0,c = -1;i < nownode.size();i ++) {
        int x = nownode[i];
        if(isring[x]) {
            if(c == -1) c = a[x];
            else if(c != a[x]) { allsame = 0; break; }
        }
	}
//   	for(int i = 0;i < maxStrs.size();i ++) cout << maxStrs[i] << endl;
    for(int i = 0,x = rings;i < ringlen;i ++) dist[x] = i,x = to[x];
    sort(maxStrs.begin(),maxStrs.end(),cmp_str_smaller);
    int maxrank = -1,ansx = -1;
   // cout << cmp_str_smaller(6,8) << endl;
    for(int k = maxStrs.size() - 1;k >= 0;k --) cout << maxStrs[k] << " " << st[maxStrs[k]] << endl;
    for(int k = maxStrs.size() - 1;k >= 0;k --) {
        if(k == 0 || cmp_str_smaller2(maxStrs[k - 1],maxStrs[k]) == 1) {
            for(int i = maxStrs.size() - 1;i >= k;i --) {
                int x = maxStrs[i];
                int now = SA :: Rank[dist[to[x]]];
                if(maxrank == -1) maxrank = now,ansx = x;
                int ansxlen = deep[st[ansx]] - deep[ansx] + 1;
                int xlen = deep[st[x]] - deep[x] + 1;
                int dlen = ansxlen - xlen;
                int nowd = to[x],ansnowd = st[ansx];
                for(int cc = 1;cc <= xlen;cc ++) ansnowd = fa[ansnowd];
                int flag = 0;
                while(dlen --) {
                    if(a[ansnowd] != a[nowd]) {
                        if(a[ansnowd] < a[nowd]) flag = 1;
                        else flag = -1;
                        break;
                    }
                    nowd = to[nowd]; ansnowd = to[ansnowd];
                }
                if(flag) {
                	if(flag == 1) maxrank = now,ansx = x;
                	else continue;
                }
                if(allsame) continue;
                if(SA :: Rank[dist[nowd]] > SA :: Rank[dist[ansnowd]])
                	maxrank = now,ansx = x;
               // cout << x << " " << dist[to[x]] << endl;
                //if(now > maxrank) maxrank = now,ansx = x;
            }
            break;
        }
    }
   //     for(int i = 0;i < ringlen * 2;i ++) cout << SA ::sa[i] << " "; puts("");
   //     for(int i = 0;i < ringlen * 2;i ++) cout << SA ::Rank[i] << " "; puts("");
    int ringans,ansid = st[ansx];
    for(int i = 0,x = rings;i <= ringlen;i ++,x = to[x])
        if(i == SA :: sa[2 * ringlen - 1])
        	ringans = x;
 //   cout << ringans << " " << rings << " " << ansid << endl;
    for(int i = 0,x = ansid,y = ringans;i < nownode.size() * 2;i ++) {
        if(a[x] != a[y]) {
        	if(a[x] < a[y]) ansid = ringans;
        	break;
        }
        x = to[x]; y = to[y];
    }
    ::ansid[id] = ansid;
    ::ringlen[id] = ringlen;
}

bool smaller(int u,int v) {
	int x = ansid[u],y = ansid[v];
    while(!use[x] && !use[y]) {
        use[x] = 1; use[y] = 1;
        if(a[x] != a[y]) return a[x] < a[y];
        x = to[x]; y = to[y];
    }
    for(int i = 0;i < max(ringlen[x],ringlen[y]);i ++) {
    	if(a[x] != a[y]) return a[x] < a[y];
        x = to[x]; y = to[y];
    }
    return a[x] < a[y];
}

void dfs_ans(int u,int d) {
	if(d == 0) { puts(""); return ; }
    printf("%c",a[u]);
    dfs_ans(to[u],d - 1);
}

void init() {
    for(int i = 0;i <= n;i ++) {
        ansid[i] = ringlen[i] = 0;
        use[i] = vis[i] = st[i] = isring[i] = 0;
        rd[i] = to[i] = 0;
        g[i].clear(); ltk[i].clear();
        dist[i] = 0;
    }
}

int main() {
	freopen("G.txt","r",stdin);
	//freopen("haha.txt","w",stdout);
    int T = read(),cc = 0;
    while(T --) {
    	n = read();
    	scanf("%s",a + 1);
    	init();
    	for(int i = 0;i < n;i ++) {
    		int v = (1ll * i * i + 1) % n;
    		int u = i + 1; v ++;
    		to[u] = v;
    		ltk[v].push_back(u);
    		ltk[u].push_back(v);
            g[v].push_back(u);
    		rd[v] ++;
   // 		cout << u << " " << v << endl;
       	}
   //    	puts("------------------");
       	int len = 0;
        for(int i = 1;i <= n;i ++) {
        	if(!vis[i]) {
                work(i,++ len);
        	}
        }
    	//for(int i = 1;i <= len;i ++) cout << ringlen[i] << " " << ansid[i] << endl;
        int now = 1;
        for(int i = 2;i <= len;i ++) {
            if(smaller(now,i)) now = i;
        }
        printf("Case #%d: ",++ cc);
        dfs_ans(ansid[now],n);
    }
    return 0;
}
/**
233
10
1234568962
Case #1: 9123689123
*/
