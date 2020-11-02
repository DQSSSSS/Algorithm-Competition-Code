#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

int n,a[SZ],s,e,f[SZ];
vector<int> g[SZ],g2[SZ],nodes[SZ];

void build(int f,int t) {
 //  cout << f << " " << t << endl;
    g[f].push_back(t);
    g2[t].push_back(f);
}

void prework() {
    for(int i = 1;i <= n*2+2;i ++) g[i].clear(),g2[i].clear();
    for(int i = 1;i <= n;i ++) f[i] = INF,nodes[i].clear();
    for(int i = 1;i <= n;i ++) {
        int x = lower_bound(f+1,f+1+n,a[i]) - f;
        f[x] = a[i];
        nodes[x].push_back(i);
        if(x > 1) {
            int l = -1,r = nodes[x-1].size()-1;
            while(r-l>1) {
                int mid = l + r >> 1;
                if(a[nodes[x-1][mid]] >= a[i]) l = mid;
                else r = mid;
            }

            build(nodes[x-1][r],i);
            if(r != nodes[x-1].size()-1)
                build(nodes[x-1][nodes[x-1].size()-1],i);
        }
    }

    for(int i = 1;i <= n;i ++) f[i] = INF,nodes[i].clear();
    for(int i = n;i >= 1;i --) {
        int x = lower_bound(f+1,f+1+n,a[i]) - f;
        f[x] = a[i];
        nodes[x].push_back(i);
        if(x > 1) {
            int l = -1,r = nodes[x-1].size()-1;
            while(r-l>1) {
                int mid = l + r >> 1;
                if(a[nodes[x-1][mid]] >= a[i]) l = mid;
                else r = mid;
            }
            build(i+n,nodes[x-1][r]+n);
            if(r != nodes[x-1].size()-1)
                build(i+n,nodes[x-1][nodes[x-1].size()-1]+n);
        }
    }

    for(int i = 1;i <= n;i ++) build(i,i+n);
    s = 2 * n + 1,e = s + 1;
    for(int i = 1;i <= n;i ++) build(s,i),build(i+n,e);
}

int dist[SZ];

void bfs(int e) {
    for(int i = 1;i <= e;i ++) dist[i] = 0;
    dist[e] = 0;
    for(int i = 2*n;i >= 1;i --) {
        for(int j : g[i]) {
            dist[i] = max(dist[i],dist[j]+1);
        }
    }
    for(int i : g[s]) {
        dist[s] = max(dist[s],dist[i]+1);
    }
}

mt19937 rd(time(0));

int main() {
//    freopen("02.in","w",stdout); n = 100000; printf("%d\n",n); for(int i = 1;i <= n;i ++) printf("%d ",rd() % 1000000001); puts("");
   // freopen("02.in","r",stdin);
    while(~scanf("%d",&n)) {
        for(int i = 1;i <= n;i ++) a[i] = read();
        prework();
        bfs(e);

      //  for(int i = 1;i <= e;i ++) printf("%d ",dist[i]); puts("");

        vector<int> ans1,ans2;

        int u = s,t = 0;
        while(u != e) {
            int nx = INF;
            for(int v : g[u]) {
                if(dist[v] + 1 == dist[u])
                    nx = min(nx,v);
            }
            if(u != s && u != e) {
                if(u <= n) ans1.push_back(u);
                else {
                    if(ans1[ans1.size()-1]+n != u) ans1.push_back(u-n);
                }
            }
            u = nx;
        }

        u = s;
        while(u != e) {
            int nx = 0;
            for(int v : g[u]) {
                if(dist[v] + 1 == dist[u])
                    nx = max(nx,v);
            }
            if(u != s && u != e) {
                if(u <= n) ans2.push_back(u);
                else {
                    if(ans2[ans2.size()-1]+n != u) ans2.push_back(u-n);
                }
            }
            u = nx;
        }

        for(int i = 0;i < ans1.size();i ++) printf("%d%c",ans1[i],i+1==ans1.size() ? '\n' : ' ');
        for(int i = 0;i < ans2.size();i ++) printf("%d%c",ans2[i],i+1==ans2.size() ? '\n' : ' ');
    }
}
