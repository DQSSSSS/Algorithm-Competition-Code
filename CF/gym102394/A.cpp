#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 3000 + 10;
const int mod = 100000007;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') { n = n * 10 + a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}

struct haha {
    int n,m;
    vector<pii> g[SZ];

    int ff[SZ * 4],tt[SZ * 4],dd[SZ * 4];

    void insert(int x,int y,int z) {
        g[x].push_back(make_pair(y,z));
       // cout << x << " " << y << " " << z << endl;
        m ++;
        ff[m] = x;
        tt[m] = y;
        dd[m] = z;
    }

    int dist[SZ],tim[SZ],use[SZ],id[SZ];

    bool hasloop2() {
        for(int i = 0;i <= n;i ++) dist[i] = 0;
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= m;j ++) {
                int u = ff[j],v = tt[j],d = dd[j];
                if(dist[v] > dist[u] + d) {
                    dist[v] = dist[u] + d;
                }
            }
        }
        for(int j = 1;j <= m;j ++) {
            int u = ff[j],v = tt[j],d = dd[j];
            if(dist[v] > dist[u] + d) {
                return true;
            }
        }
        return false;
    }

    bool hasloop() {
        deque<int> q;
        for(int i = 0;i <= n;i ++) id[i] = i;
        //random_shuffle(id,id+1+n);
        for(int x = 0;x <= n;x ++) {
            int i = id[x];
          //  random_shuffle(g[i].begin(),g[i].end());
            q.push_back(i);
            dist[i] = 0;
            use[i] = 1;
            tim[i] = 0;
        }
        while(q.size()) {
            if(q.size() > 2) {
                int u = q.front(),v = q.back();
                if(dist[u] > dist[v]) {
                    q.pop_front(); q.pop_back();
                    q.push_front(v);
                    q.push_front(u);
                }
            }
            int u = q.front(); q.pop_front();
            use[u] = 0;
            //cout << u << endl;
            for(pii p : g[u]) {
                int v = p.first;
                if(dist[v] > dist[u] + p.second) {
                    dist[v] = dist[u] + p.second;
                    tim[v] = tim[u] + 1;
                    if(tim[v] >= n+1) return true;
                    if(!use[v]) {
                        use[v] = 1; q.push_back(v);
                    }
                }
            }
        }
        //for(int i = 0;i <= n;i ++) printf("%d ",dist[i]); puts("");
        //puts("??");
        return false;
    }

    void init(int nn) {
        n = nn; m = 0;
        for(int i = 0;i <= nn;i ++) g[i].clear();
    }
}graph;

struct hahha {
    int l,r,k;
}a[SZ],b[SZ];

int n,m1,m2;

bool check(int mid) {
    graph.init(n);
    for(int i = 1;i <= n;i ++) {
        graph.insert(i-1,i,1);
        graph.insert(i,i-1,0);
    }
    for(int i = 1;i <= m1;i ++) {
        int l = a[i].l-1;
        int r = a[i].r;
        int k = a[i].k;
        graph.insert(r,l,-k);
    }

    for(int i = 1;i <= m2;i ++) {
        int l = b[i].l-1;
        int r = b[i].r;
        int k = b[i].k;
        graph.insert(l,r,mid-k);
    }
    graph.insert(0,n,mid);
    graph.insert(n,0,-mid);
    if(graph.hasloop2()) return false;
    return true;
}

int main() {
    int T = read();
    while(T --) {
        n = read(),m1 = read(),m2 = read();
        for(int i = 1;i <= m1;i ++) a[i].l = read(),a[i].r = read(),a[i].k = read();
        for(int i = 1;i <= m2;i ++) b[i].l = read(),b[i].r = read(),b[i].k = read();
       // check(0); return 0;
        int l = -1,r = n;
        while(r-l>1) {
            int mid = l + r >> 1;
            if(check(mid)) r = mid;
            else l = mid;
        }
        printf("%d\n",r);
    }
}
