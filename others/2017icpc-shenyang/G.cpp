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
		//memset(sa,0,sizeof sa);
		//memset(Rank,0,sizeof Rank);
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
		/*puts("--------------");
		cout << s << endl;
        for(int i = 0;i <= len;i ++) cout << sa[i] << " "; puts("");
        puts("--------------");*/
	}
}

int n,to[SZ],rd[SZ];
bool isring[SZ];

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
}

char a[SZ];

/*ULL nowString[SZ];
const ULL BASE = 233;

void dfs(int u,int d) {
    nowString[d] = nowString[d - 1] * BASE + a[u];
    for(int i = 0;i < g[u].size();i ++) {
    	int v = g[u][i];
        dfs(v,d + 1);
    }
}*/


struct haha {
    int start,ed;
    bool isring;
    string s;
}s,maxsuf;

bool cmp(const haha &a,const haha &b) {
	if(a.s != b.s) return a.s > b.s;
	return a.isring > b.isring;
}

void get_str_ring(int u,int ed) {
    s.s += a[u];
    if(to[u] == ed) { return ; }
    get_str_ring(to[u],ed);
}

void find_max_suf() {
	int len = s.s.length();
	for(int i = 0;i < len;i ++) s.s += s.s[i];
	SA :: get_sa(s.s);
	int pos = SA :: sa[s.s.length() - 1],res = s.s.length() - pos;
	int x = s.start;
	while(pos --) x = to[x];
	maxsuf.start = x;
	while(res --) maxsuf.s += a[x],x = to[x];
	maxsuf.isring = 1;
}

void find_ring() {
	for(int i = 1;i <= n;i ++)
		if(!Tarjan :: dfn[i])
			Tarjan :: tarjan(i);
	bool flag = 0;
	for(int i = 1;i <= Tarjan :: scccnt;i ++) {
		if(Tarjan :: g[i].size() > 1) {
			for(int j = 0;j < Tarjan :: g[i].size();j ++)
				isring[Tarjan :: g[i][j]] = 1;
			flag = 1;
			break;
		}
	}
	if(!flag)
		for(int i = 1;i <= n;i ++)
			if(to[i] == i) isring[i] = 1;
}

int ringlen = 0,dist[SZ];
char str[SZ],ans[SZ];

void dfs_ans(int u,int d) {
    if(d == n + 1) return ;
    ans[d] = a[u];
    dfs_ans(to[u],d + 1);
}

void init() {
    for(int i = 1;i <= n;i ++) {
    //	rd[i] = 0; g[i].clear();
		Tarjan :: dfn[i] = Tarjan :: low[i] = Tarjan :: sccnum[i] = 0;
		Tarjan :: g[i].clear();
		isring[i] = 0;
		dist[i] = 0;
	}
	s.s = ""; s.start = s.ed = s.isring = 0;
	maxsuf.s = ""; maxsuf.start = maxsuf.ed = maxsuf.isring = 0;
	Tarjan :: scccnt = 0; Tarjan :: dfs_clock = 0;
	ringlen = 0;
}

bool vis[SZ];
int anss = 0;
void dfs_haha(int u) {
	//cout << u << endl;
	if(vis[u]) return ;
	vis[u] = 1; anss ++;
	dfs_haha(to[u]);
}

int main() {
	freopen("G.txt","r",stdin);
    int T = read(),cc = 0;
    while(T --) {
        //init();
        n = read();
        scanf("%s",str);
        for(int i = 0;i < n;i ++){
           // a[i + 1] = str[i];
            int v = (1ll * i * i + 1) % n + 1;
            to[i + 1] = v;
//           	g[v].push_back(i);
        	rd[v] ++;
        }
        for(int i = 1;i <= n;i ++)
        	if(!rd[i]) { anss = 0; dfs_haha(i); cout << anss << endl; }
        find_ring();
        for(int i = 1;i <= n;i ++) if(isring[i]) ringlen ++;
        for(int i = 1;i <= n;i ++) {
			if(isring[i]) {
                get_str_ring(i,i);
                s.start = i;
                s.isring = 1;
                break;
			}
		}
        find_max_suf();

        for(int i = 1;i <= n;i ++) {
        	if(!isring[i] && isring[to[i]]) {
                dfs(i,1);
        	}
        }

		for(int i = 1;i <= len;i ++)
        	cout << s[i].start << " " << s[i].s << " " << s[i].ed << " " << s[i].isring << endl;

        for(int i = 1;i <= len;i ++)
        	cout << s[i].start << " " << s[i].s << " " << maxsuf[i].s << endl;


        printf("Case #%d: ",++ cc);
        if(maxsuf[1].isring) {
            dfs_ans(maxsuf[1].start,1);
			for(int i = 1;i <= n;i ++)
				printf("%c",ans[i]); puts("");
        }
        else {
			bool allsame = 1;
       		for(int i = 1,x = -1;i <= n;i ++)
				if(isring[i]) {
					if(x == -1) x = a[i];
					else if(x != a[i]) { allsame = 0; break; }
				}
			if(allsame) {
				dfs_ans(maxsuf[1].start,1);
				for(int i = 1;i <= n;i ++)
					printf("%c",ans[i]); puts("");
			}
			else {
				assert(s[len].isring);
                int x = s[len].start;
                dist[x] = 0;
                for(int i = 1;i < ringlen;i ++) dist[x = to[x]] = i;
                int maxrank = 0,ansid = 0;
				for(int k = 1;k <= n;k ++) {
					if(k == n || maxsuf[k].s != maxsuf[k + 1].s) {
                        for(int i = 1;i <= k;i ++) {
	                        int x = maxsuf[i].ed;
    	                    int now = SA :: Rank[dist[x]];
        	                if(now > maxrank)
        	                	maxrank = now,ansid = maxsuf[i].start;
						}
						break;
					}
				}
				dfs_ans(maxsuf[1].start,1);
				for(int i = 1;i <= n;i ++)
					printf("%c",ans[i]); puts("");
			}
		}
    }
    return 0;
}
