#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 600010;
const int INF = 1e9 + 10;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int maxn = 0;
vector<int> g[SZ * 5];
int rd[SZ * 5],a[SZ],val[SZ],sum[SZ];
map<int,int> id;
pair<int,int> tmp[SZ];

void build(int f,int t) {
	if(!f) return ;
    maxn = max(maxn,f);
    //cout << f << " " << t << endl;
	g[f].push_back(t);
	rd[t] ++;
}

int n,m;

struct haha {
    int l,r,id;
}tree[SZ * 4];

void update(int p) {
    if(tree[p].r == tree[p].l) return ;
	build(tree[p << 1].id,tree[p].id);
	build(tree[p << 1 | 1].id,tree[p].id);
}

void build(int p,int l,int r) {
	tree[p] = (haha){l,r,p + n};
    if(l == r) {
    	if(a[l - 1] == -1) tree[p].id = 0;
		else tree[p].id = id[a[l - 1]];
   		return ;
    }
    int mid = l + r >> 1;
    build(p << 1,l,mid); build(p << 1 | 1,mid + 1,r);
    update(p);
}

void build(int p,int l,int r,int v) {
	if(l > r) return ;
    if(l <= tree[p].l && tree[p].r <= r) {
        build(tree[p].id,v);
        return ;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) build(p << 1,l,r,v);
    if(mid < r) build(p << 1 | 1,l,r,v);
}

priority_queue<pair<int,int> > q;
vector<int> ans;

void topo(){
	while(q.size()) q.pop();
    for(int i = 1;i <= n;i ++) {
        if(rd[i] == 0) q.push(make_pair(-val[i],i));
    }
    while(q.size()) {
        pair<int,int> u = q.top(); q.pop();
        if(u.second <= n)
	        ans.push_back(-u.first);
        for(int i = 0;i < g[u.second].size();i ++) {
            int v = g[u.second][i];
            if(!-- rd[v]) {
                int x = 0;
                if(v <= n) x = val[v];
                q.push(make_pair(-x,v));
            }
        }
    }
}

void init() {
	ans.clear(); id.clear();
	for(int i = 1;i <= maxn;i ++)
        g[i].clear(),rd[i] = 0;
    for(int i = 0;i < 2 * m;i ++) sum[i] = 0;
	maxn = 0;
}

int main() {
    int T = read();
    while(T --) {
        m = read(),n = 0;
        init();
		//cout << maxn << endl;
        for(int i = 0;i < m;i ++) {
        	a[i + m] = a[i] = read();
        	if(a[i] == -1) continue;
        	id[a[i]] = ++ n,val[n] = a[i];
		}
		for(int i = 0;i < 2 * m;i ++) {
		//	if(a[i] == -1) continue;
        	tmp[i] = make_pair(-1,i);
		}

		sum[0] = (a[0] != -1);
		for(int i = 1;i < 2 * m;i ++) {
			sum[i] = sum[i - 1] + (a[i] != -1);
		}

		//for(int i = 0;i < 2 * m;i ++) cout << sum[i] << " "; puts("");
		build(1,1,2 * m);
		bool f = 0;
		for(int i = 0;i < 2 * m;i ++) {
            if(a[i] == -1) continue;
            int x = a[i] % m;
            if(x <= i && i < x + m) {
                if(tmp[x].first != -1) {
                   	int u = tmp[x].first,v = id[a[i]];
                    build(1,tmp[x].second + 1,i,v);
                    if(sum[i] - (tmp[x].second == 0 ? 0 : sum[tmp[x].second - 1]) != i - tmp[x].second + 1)
                    	f = 1;
                } else {
               		int v = id[a[i]];
					build(1,x + 1,i,v);
					if(sum[i] - (x == 0 ? 0 : sum[x - 1]) != i - x + 1)
						f = 1;
					//cout << x << " " << i << endl;
                }
                tmp[x] = make_pair(id[a[i]],i);
            }
		}
		if(f) { puts("-1"); continue; }

        topo();
        if(!q.size())
       		for(int i = 0;i < n;i ++)
       	    	printf("%d%c",ans[i],i == n - 1 ? '\n' : ' ');
        else
        	puts("-1");
    }
    return 0;
}
