#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;
const double eps = 1e-6;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

struct point {
    int x,y;
    void read() { x=::read(); y=::read(); }
    void print() { printf("%d %d\n",x,y); }
    LL operator ^(point o) { return x*o.y-y*o.x; }
    LL operator *(point o) { return x*o.x+y*o.y; }
    point operator -(point o) { return (point){x-o.x,y-o.y}; }
};

vector<point> city[SZ];
int dw[SZ];

point calc(point a,point b,point c) {
    if(((a-b) * (c-b)) == 0) swap(a,b);
    else if(((a-c) * (b-c)) == 0) swap(a,c);
    return (point){b.x+c.x-a.x,b.y+c.y-a.y};
}

struct edge {
    int t;
    double d;
};

vector<edge> g[SZ];

double dist[SZ];
bool vis[SZ];

double dij(int s,int e) {
    for(int i = 1;i <= e;i ++) dist[i] = 1e100,vis[i] = 0;
    dist[s] = 0;
    priority_queue<pair<double,int> > q;
    q.push(make_pair(0,s));
    while(q.size()) {
        int u = q.top().second; q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(edge e : g[u]) {
            int v = e.t;
            if(dist[v] > dist[u] + e.d + eps) {
                dist[v] = dist[u] + e.d;
                q.push(make_pair(-dist[v],v));
            }
        }
    }
    return dist[e];
}

double pf(double x) { return x * x; }

int main() {
    int T = read();
    while(T --) {
        int m = read(),tt = read(),A = read(),B = read();
        for(int i = 1;i <= m;i ++) city[i].clear();
        for(int i = 1;i <= m;i ++) {
            point a,b,c,d;
            a.read(); b.read(); c.read();
            dw[i] = read();
            d = calc(a,b,c);
            city[i].push_back(a); city[i].push_back(b);
            city[i].push_back(c); city[i].push_back(d);
        }
        int s = m * 4 + 1,e = s + 1;
        for(int i = 1;i <= e;i ++) g[i].clear();
        for(int i = 1;i <= m;i ++) {
            for(int a = 0;a < 4;a ++) {
                for(int b = a+1;b < 4;b ++) {
                    int u = (i-1)*4+a+1;
                    int v = (i-1)*4+b+1;
                    point p1 = city[i][a];
                    point p2 = city[i][b];
                    double d = sqrt(pf(p1.x-p2.x)+pf(p1.y-p2.y)) * dw[i];
                    g[u].push_back((edge){v,d});
                    g[v].push_back((edge){u,d});
                }
            }
        }

        for(int i = 1;i <= m;i ++) {
            for(int j = i+1;j <= m;j ++) {
                for(int a = 0;a < 4;a ++) {
                    for(int b = 0;b < 4;b ++) {
                        int u = (i-1)*4+a+1;
                        int v = (j-1)*4+b+1;
                        point p1 = city[i][a];
                        point p2 = city[j][b];
                        double d = sqrt(pf(p1.x-p2.x)+pf(p1.y-p2.y)) * tt;
                        g[u].push_back((edge){v,d});
                        g[v].push_back((edge){u,d});
                    }
                }
            }
        }

        g[s].push_back((edge){(A-1)*4+1,0});
        g[s].push_back((edge){(A-1)*4+2,0});
        g[s].push_back((edge){(A-1)*4+3,0});
        g[s].push_back((edge){(A-1)*4+4,0});

        g[(B-1)*4+1].push_back((edge){e,0});
        g[(B-1)*4+2].push_back((edge){e,0});
        g[(B-1)*4+3].push_back((edge){e,0});
        g[(B-1)*4+4].push_back((edge){e,0});

        printf("%.1f\n",dij(s,e));
    }
}


/**
3 10 1 3
1 1 1 3 3 1 30
2 5 7 4 5 2 1
8 6 8 8 11 6 3
*/
