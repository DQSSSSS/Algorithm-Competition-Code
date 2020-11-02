#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2e5 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

struct edge {
    int f,t;
    LL d,c;
}l[SZ];

int n,m,head[SZ],nxt[SZ],tot = 1,totp;

void build(int f,int t,LL d,LL c) {
    l[++ tot] = (edge){f,t,d,c};
    nxt[tot] = head[f];
    head[f] = tot;
}

void insert(int f,int t,LL d,LL c) {
   // printf("%d->%d %lld %lld\n",f,t,d,c);
    build(f,t,d,c); build(t,f,0,-c);
}

struct MAMF{

    LL dist[SZ];
    queue<int> q;
    bool use[SZ];
    int pre[SZ];

    bool spfa(int s,int e) {
        for(int i = 0;i <= e;i ++) pre[i] = 0,use[i] = 0,dist[i] = -1e18;
        dist[s] = 0;
        q.push(s);
        while(q.size()) {
            int u = q.front(); q.pop();
            use[u] = 0;
            for(int i = head[u];i;i = nxt[i]) {
                int v = l[i].t;
                if(l[i].d && dist[v] < dist[u] + l[i].c) {
                    dist[v] = dist[u] + l[i].c;
                    pre[v] = i;
                    if(!use[v]) {
                        use[v] = 1; q.push(v);
                    }
                }
            }
        }
        return dist[e] != -1e18;
    }

    LL mcmf(int s,int e) {
        LL ans = 0;
        while(spfa(s,e)) {
            LL maxflow = INF;
            for(int i = pre[e];i;i = pre[l[i].f])
                maxflow = min(maxflow,l[i].d);
            for(int i = pre[e];i;i = pre[l[i].f])
                ans += l[i].c * maxflow,l[i].d -= maxflow,l[i^1].d += maxflow;
        }
        return ans;
    }
}ek;

char mp[55][55];

int value[55][55];
int cost[55][55];

struct haha {
    int r,c,b[5];
}a[55][55];

bool isTurning(char c) {
    return c == '>' || c == '<' || c == '^' || c == 'v';
}

bool isin(int x,int y) {
    return x>=1 && x<=n && y>=1 && y<=m;
}

bool isSource(char c) {
    return c == 'L' || c == 'R' || c == 'U' || c == 'D';
}

pii getDir(char c) {
    if(c == 'L' || c == '<') return make_pair(0,-1);
    if(c == 'R' || c == '>') return make_pair(0,1);
    if(c == 'U' || c == '^') return make_pair(-1,0);
    if(c == 'D' || c == 'v') return make_pair(1,0);
    assert(0);
}

int find(int x,int y,int dx,int dy) {
    do {
        x += dx; y += dy;
        if(!isin(x,y)) return 0;
        char c = mp[x][y];
        if(c == '#') return 0;
        if(c == 'x' || isTurning(c)) return a[x][y].r;
    }while(isin(x,y) && (mp[x][y] == '.' || isSource(mp[x][y])));
    assert(0);
}

const char dy[] = "^>v<";

int get(char a) {
    int A=-1;
    for(int i = 0;i < 4;i ++) if(dy[i] == a) A=i;
    assert(A!=-1);
    return A;
}

int getTimes(char a,char b) {
    assert(isTurning(a));
    assert(isTurning(b));
    return (get(b) - get(a) + 4) % 4;
}

int main() {
   // freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    int T = read();
    while(T --) {
        n = read(),m = read();
        int k = read(),l = read();
        for(int i = 1;i <= n;i ++) scanf("%s",mp[i]+1);
        for(int i = 1;i <= k;i ++) {
            int x = read(),y = read(),z = read();
            value[x][y] = z;
        }
        for(int i = 1;i <= l;i ++) {
            int x = read(),y = read(),z = read();
            cost[x][y] = z;
        }

        for(int i = 0;i <= totp;i ++) head[i] = 0;
        tot = 1;
        totp = 1;

        int s = 1,null = 0;
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= m;j ++) {
                char c = mp[i][j];
                if(isTurning(c)) {
                    a[i][j].r = ++ totp;
                    a[i][j].c = ++ totp;
                    for(int k = 0;k < 4;k ++) a[i][j].b[k] = ++ totp;
                }
                if(isSource(c) || c == 'x') {
                    a[i][j].r = ++ totp;
                }
            }
        int e = ++ totp;
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= m;j ++) {
                char c = mp[i][j];
                if(c == '.') continue;

                if(isSource(c)) {
                    insert(s,a[i][j].r,1,0);
                    pii x = getDir(c);
                    int y = find(i,j,x.first,x.second);
                    if(y) insert(a[i][j].r,y,1,0);
                    insert(a[i][j].r,e,1,0);
                }
                else if(isTurning(c)) {
                    LL x = cost[i][j];
                    insert(a[i][j].r,a[i][j].c,1,0);
                    for(int k = 0;k < 4;k ++) {
                      //  printf("%d %d %d\n",i,j,getTimes(c,dy[k]));
                        insert(a[i][j].c,a[i][j].b[k],1,-x*getTimes(c,dy[k]));
                        pii t = getDir(dy[k]);
                        int x = find(i,j,t.first,t.second);
                        if(x) insert(a[i][j].b[k],x,1,0);
                    }
                }
                else if(c == 'x') {
                    insert(a[i][j].r,e,1,value[i][j]);
             //       insert(a[i][j].r,0,INF,0);
                }
            }
        }
       // insert(0,e,INF,0);
        printf("%lld\n",ek.mcmf(s,e));
    }
}

/**
5
1 5 1 0
R...x
1 5 3

1 5 1 1
x.R.v
1 1 5
1 5 1

1 5 1 1
x.R.v
1 1 1
1 5 5

3 5 1 4
>L#R>
.###.
<.x.>
3 3 100
1 1 3
1 5 1
3 1 0
3 5 0

3 5 1 5
.v<..
R.>.>
.>..x
3 5 100
1 2 999
1 3 999
2 3 1
2 5 3
3 2 999

*/
