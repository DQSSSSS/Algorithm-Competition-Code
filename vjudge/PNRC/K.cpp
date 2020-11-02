#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pll;
const int SZ = 1000010;
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

vector<int> g[SZ];

struct haha {
    LL x,y,z;
};

bool operator <(haha a,haha b) {
    if(a.x != b.x) return a.x < b.x;
    if(a.y != b.y) return a.y < b.y;
    return a.z < b.z;
}

map<haha,int> mp;

const int B2 = 233,B1 = 2333,B3 = 41;
const int p2 = 999980411,p1 = 999984233,p3 = 999987871;
int mi1[SZ],mi2[SZ],mi3[SZ];

int a[SZ];
int sz[SZ],ans = 0;

haha dfs1(int u,int fa) {
    LL h1 = a[u],h2 = 0,h3 = 0;
    sz[u] = 1;
    for(int v : g[u]) {
        if(v == fa) continue;
        haha t = dfs1(v,u);
        h1 = (h1 * mi1[sz[v]] + t.x) % p1;
        h2 = (h2 * mi2[sz[v]] + t.y) % p2;

        h3 = (h3 * mi3[sz[v]] + t.z) % p3;
        h3 = (h3 * B3 + a[u]) % p3;
        sz[u] += sz[v];
    }
    h2 = (h2 * B2 + a[u]) % p2;
    mp[(haha){0,h2,h3}] = 1;
    //cout << u << " " << h1 << " " << h2 << " " << h3 << endl;
    return (haha){h1,h2,h3};
}

haha dfs2(int u,int fa) {
    LL h1 = a[u],h2 = 0,h3 = 0;
    sz[u] = 1;
    for(int v : g[u]) {
        if(v == fa) continue;
        haha t = dfs2(v,u);
        h1 = (h1 * mi1[sz[v]] + t.x) % p1;
        h2 = (h2 * mi2[sz[v]] + t.y) % p2;

        h3 = (h3 * mi3[sz[v]] + t.z) % p3;
        h3 = (h3 * B3 + a[u]) % p3;
        sz[u] += sz[v];
    }
    h2 = (h2 * B2 + a[u]) % p2;
    if(mp.count((haha){0,h2,h3}))
        ans = max(ans,sz[u]);
    //cout << u << " " << h1 << " " << h2 << " " << h3 << endl;
    return (haha){h1,h2,h3};
}

int main() {
    mi1[0] = 1;
    mi2[0] = 1;
    mi3[0] = 1;
    for(int i = 1;i <= 10000;i ++) mi1[i] = 1ll * mi1[i-1] * B1 % p1;
    for(int i = 1;i <= 10000;i ++) mi2[i] = 1ll * mi2[i-1] * B2 % p2;
    for(int i = 1;i <= 10000;i ++) mi3[i] = 1ll * mi3[i-1] * B3 % p3;
    int T = read();
    while(T --) {
        int n = read(),m = read();
        for(int i = 1;i <= n+m;i ++) g[i].clear();
        mp.clear();
        int rt1,rt2;
        for(int i = 1;i <= n;i ++) {
            char s[2];
            int x;
            scanf("%s%d",s,&x);
            a[i] = s[0] - 'A' + 1;
            x ++;
            if(x) g[x].push_back(i);
            else rt1 = i;
        }
        for(int i = n+1;i <= n+m;i ++) {
            char s[2];
            int x;
            scanf("%s%d",s,&x);
            a[i] = s[0] - 'A' + 1;
            x ++;
            x += n;
            if(x>n) g[x].push_back(i);
            else rt2 = i;
        }

        for(int i = 1;i <= n+m;i ++) sort(g[i].begin(),g[i].end());

        ans = 0;
        dfs1(rt1,0);
       // puts("");
        dfs2(rt2,0);
        printf("%d\n",ans);
    }
}

