#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int SZ = 2000010;
const int INF = 1e9 + 10;
const int mod = 1e9+7;
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

struct GRAPH {
    struct edge {
        int t,d;
    };

    vector<edge> G[SZ];

    void addEdge(int x,int y,int w) {
        G[x].push_back({y,w});
        G[y].push_back({x,w});
    }

    int dist[4][SZ],vis[SZ],n;

    void dij(int s,int dist[]) {
        for(int i = 1;i <= n;i ++) dist[i]=INF,vis[i]=0;
        priority_queue<pii> q;
        q.push({0,s});
        dist[s] = 0;
        while(q.size()) {
            int u = q.top().second; q.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            for(edge e : G[u]) {
                int v = e.t;
                if(dist[v] > dist[u] + e.d) {
                   dist[v] = dist[u] + e.d;
                   q.push({-dist[v],v});
                }
            }
        }
    }

    void init(int nn) {
        n = nn;
    }

}graph;


struct BIT {
    int tree[SZ],n;

    void add(int x,int d) {
        for(int i = x;i <= n;i += i & -i) tree[i] += d;
    }

    int ask(int x) {
        int ans = 0;
        for(int i = x;i > 0;i -= i & -i) ans += tree[i];
        return ans;
    }

    void init(int nn) {
        n = nn;
    }
}bit;

struct haha {
    int x,y,z,t,v;
}a[SZ],tmp[SZ];

bool cmp(haha a,haha b) {
    if(a.x != b.x) return a.x < b.x;
    if(a.y != b.y) return a.y < b.y;
    return a.z < b.z;
}

bool operator ==(haha a,haha b) {
    return a.x==b.x && a.y==b.y && a.z==b.z;
}

bool operator !=(haha a,haha b) {
    return !(a==b);
}

int lsh[SZ];


void cdq(int l,int r) {
    if(l >= r) return ;
    int mid = l + r >> 1;
    cdq(l,mid); cdq(mid+1,r);
    int pl = l,pr = mid + 1,p = l;
    while(pl <= mid || pr <= r) {
        if(pr > r || (pl <= mid && a[pl].y <= a[pr].y)) {
            bit.add(a[pl].z,1);
            tmp[p ++] = a[pl ++];
        }
        else {
            a[pr].v |= bit.ask(a[pr].z) > 0;
            tmp[p ++] = a[pr ++];
        }
    }
    for(int i = l;i <= r;i ++) {
        if(i <= mid) bit.add(a[i].z,-1);
        a[i] = tmp[i];
    }
}

int main() {
    int n = read(),m = read();
    graph.init(n);
    for(int i = 1;i <= m;i ++) {
        int x = read()+1,y = read()+1,w = read();
        graph.addEdge(x,y,w);
    }
    graph.dij(1,graph.dist[1]);
    graph.dij(2,graph.dist[2]);
    graph.dij(3,graph.dist[3]);
    for(int i = 1;i <= n;i ++) {
        a[i] = (haha){graph.dist[1][i],graph.dist[2][i],graph.dist[3][i],1,0};
    }
    sort(a+1,a+1+n,cmp);
    int tot = 0;
    for(int i = 1,j = 1;i <= n;i ++) {
        if(i == n || a[i] != a[i+1]) {
            haha t = a[i]; t.t = i-j+1;
            a[++ tot] = t;
            j = i + 1;
        }
    }
    for(int i = 1;i <= tot;i ++) {
        lsh[++ lsh[0]] = a[i].x;
        lsh[++ lsh[0]] = a[i].y;
        lsh[++ lsh[0]] = a[i].z;
    }
    sort(lsh+1,lsh+1+lsh[0]);
    lsh[0] = unique(lsh+1,lsh+1+lsh[0])-lsh-1;
    for(int i = 1;i <= tot;i ++) {
        a[i].x = lower_bound(lsh+1,lsh+1+lsh[0],a[i].x) - lsh;
        a[i].y = lower_bound(lsh+1,lsh+1+lsh[0],a[i].y) - lsh;
        a[i].z = lower_bound(lsh+1,lsh+1+lsh[0],a[i].z) - lsh;
    }

    bit.init(lsh[0]);
    cdq(1,tot);

    int ans = 0;
    for(int i = 1;i <= tot;i ++) {
        ans += a[i].v * a[i].t;
    }
    cout << n - ans << endl;
}
