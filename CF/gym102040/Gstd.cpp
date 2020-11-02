#include <bits/stdc++.h>
using namespace std;

const int N = 1<<17;

int sz[N], used[N], a[N], b[N], c[N];
vector<int> adj[N], tree[N];

void dfs(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (used[v] || v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int get_centroid(int u) {
    int s = sz[u];
    while (1) {
        int found = 1;
        for (int v : adj[u]) {
            if (used[v] || sz[v] > sz[u]) continue;
            if (sz[v] * 2 > s) {
                u = v;
                found = 0;
                break;
            }
        }
        if (found) return u;
    }
    assert(0);
}

const int inf = 1e9;
struct SegTree {
    int n;
    vector<int> d;
    SegTree() {n = 0; d.clear(); };
    SegTree(vector<int> &v) {
        n = v.size();
        int m = 1;
        while (m < n) m *= 2;
        d.resize(m + m);
        n = m;
        for (int i = n; i < n + v.size(); i++) d[i] = v[i - n];
        for (int i = n-1; i > 0; i--) d[i] = min(d[i + i], d[i + i + 1]);
//        cerr << "n = " << n << ' ' << d.size() << endl;
    }
    int query(int l, int r) { // [l, r)
        assert(l >= 0 && r <= n && l <= r);
        l += n, r += n;
        int ans = inf;
//        cerr << "l = " << n << ' ' << l << ' ' << r << endl;
        while (l < r) {
//            cerr << l << ' ' << r << endl;
            if (l & 1) ans = min(ans, d[l]);
            if (r & 1) ans = min(ans, d[r - 1]);
            l = l + 1 >> 1, r >>= 1;
        }
        return ans;
    }
} s[N];

vector<int> all;

int dis[N];

void dfs(int u, int p, int d) {
    all.push_back(u);
    dis[u] = d;
    for (int v : adj[u]) {
        if (v == p || used[v]) continue;
        dfs(v, u, d + 1);
    }
}

vector<pair<int, int> > cen[N];

void process(int u) {
    all.clear();
    dfs(u, 0, 0);
    sort(all.begin(), all.end());
    tree[u] = all;
    vector<int> d;
    for (int x : all) d.push_back(dis[x]);
    s[u] = SegTree(d);
    for (int x : all) cen[x].push_back(make_pair(u, dis[x]));
}

void solve(int u) {
    dfs(u, 0);
    u = get_centroid(u);
    cerr << "u = " << u << endl;
    process(u);
    used[u] = 1;
    for (int v : adj[u]) {
        if (used[v]) continue;
        solve(v);
    }
}

inline int rnd() {
	return ((rand() << 15) | rand());
}

int main() {
//    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ncase, casen = 0;
    cin >> ncase;
    for (; ncase--; ) {
        printf("Case %d:\n", ++casen);
        int n;
		cin >> n;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            tree[i].clear();
            cen[i].clear();
            s[i] = SegTree();
            used[i] = 0;
        }
        for (int i = 1; i < n; i++) {
            int u, v;
			cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        solve(1);
        auto calc = [&](int l, int r, int u) {
            if (u >= l && u <= r) return 0;
//            cerr << u << ' ' << l << ' ' << r << endl;
            int ret = inf;
            for (auto t : cen[u]) {
                int v = t.first;
                int d = t.second;
                int st = lower_bound(tree[v].begin(), tree[v].end(), l) - tree[v].begin();
                int en = upper_bound(tree[v].begin(), tree[v].end(), r) - tree[v].begin();
//                cerr << st << ' ' << en << endl;
                if (st == en) continue;
                ret = min(ret, s[v].query(st, en) + d);
            }
            return ret;
        };
        int q;
		cin >> q;
		int tot = 0;
		vector<int> temp;
        while (q--) {
            int op;
			cin >> op;
            if (op == 1) {
                int x, l, r;
				cin >> x >> l >> r;
                a[x] = l, b[x] = r, c[x] = casen;
            } else if (op == 2) {
                int x;
				cin >> x;
				c[x] = 0;
            } else {
                int u, m;
				cin >> u >> m;
                int ans = n;
                while (m--) {
                    int x;
					cin >> x;
                    if (c[x] != casen) continue;
                    ans = min(ans, calc(a[x], b[x], u));
                }
                if (ans == n) puts("-1");
                else printf("%d\n", ans);
            }
        }
    }
    return 0;
}
