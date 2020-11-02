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

struct haha {
	string s;
	int id;
}ans[SZ];

bool cmp(const haha &a,const haha &b) { return a.s < b.s; }

int to[SZ],rd[SZ];
char a[SZ];

void dfs(int u,int id,int d) {
	if(d == 0) return ;
    ans[id].s += a[u];
    dfs(to[u],id,d - 1);
}

void dfs_ans(int u,int d) {
	//cout << u + 1 << endl;
	if(d == 0) { puts(""); return ; }
    printf("%c",a[u]);
    dfs_ans(to[u],d - 1);
}

int t,maxsz;
bool vis[SZ];

void dfs_ltk(int u) {
    if(vis[u]) return ;
    t ++; vis[u] = 1;
    maxsz = max(maxsz,t);
    dfs_ltk(to[u]);
}

int main() {
	freopen("G.txt","r",stdin);
	freopen("std.txt","w",stdout);
    int T = read(),cc = 0;
    while(T --) {
    	int n = read();
    	scanf("%s",a);
    	for(int i = 0;i < n;i ++) rd[i] = vis[i] = 0;
    	maxsz = 0;
    	for(int i = 0;i < n;i ++) {
    		to[i] = (1ll * i * i + 1) % n;
    		rd[(1ll * i * i + 1) % n] ++;
       	}
        for(int i = 0;i < n;i ++) if(rd[i] == 0) t = 0,dfs_ltk(i);
        for(int i = 0;i < n;i ++) {
        	ans[i].s = "";
			dfs(i,i,2 * maxsz);
			ans[i].id = i;
        }
        sort(ans,ans + n,cmp);
        printf("Case #%d: ",++ cc);
       // cout << ans[n - 1].id << endl;
        dfs_ans(ans[n - 1].id,n);
    }
    return 0;
}
