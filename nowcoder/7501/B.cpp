#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<double,int> pdi;
const int SZ = 2e6 + 10;
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

struct GRAPH {

    struct edge {
        int t;
        double d;
    };

    vector<edge> G[SZ];

    void addEdge(int x,int y,double dis) {
        G[x].push_back({y,dis});
    }

    int n;
    double dist[SZ];
    bool vis[SZ];

    double dij(int s,int e) {
        for(int i = 0;i <= n;i ++) dist[i] = INF,vis[i] = 0;
        dist[s] = 0;
        priority_queue<pdi> q;
        q.push({0,s});
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
        return dist[e];
    }

    void init(int nn) {
        n = nn;
        for(int i = 0;i <= n;i ++) G[i].clear();
    }
}graph;

int sgn(double x) {
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}

struct Point {
    double x,y;
    Point(double x=0,double y=0):x(x),y(y) {}
    double operator ^(const Point &o) const { return x*o.y-y*o.x; }
    double operator *(const Point &o) const { return x*o.x+y*o.y; }
    Point operator +(const Point &o) const { return Point(x+o.x,y+o.y); }
    Point operator -(const Point &o) const { return Point(x-o.x,y-o.y); }
    double len2() const { return x*x+y*y; }
    double len() const { return sqrt(len2()); }
    bool same(const Point &o) const { return sgn(x-o.x)==0 && sgn(y-o.y)==0; }

    void read() { x=::read(); y=::read(); }
    void print() const { printf("(%.6f,%.6f) ",x,y); }
}S, T;

struct Seg {
    Point s,e;

    Seg(const Point &s=Point(0,0),const Point &e=Point(0,0)):s(s),e(e) {}

    bool isPointAtSeg(const Point &p) const {
        return sgn((p-s)^(e-s)) == 0 && sgn((p-s)^(p-e)) <= 0;
    }
    Point lineProg(const Point &p) const {
        return s + ( ((e-s)*((e-s)*(p-s)))/((e-s).len2()) );
    }

    bool parallel(const Seg &v) const {
        return sgn((e-s)^(v.e-v.s)) == 0;
    }
    //点和直线关系
    //1 在左侧
    //2 在右侧
    //3 在直线上
    int relation(const Point &p) const {
        int c = sgn((p-s)^(e-s));
        if(c < 0)return 1;
        else if(c > 0)return 2;
        else return 3;
    }

    //2:规范 1:非规范(重合，端点重合) 0:不
    int segCrossSeg(const Seg &v) const {
        int d1 = sgn((e-s)^(v.s-s));
        int d2 = sgn((e-s)^(v.e-s));
        int d3 = sgn((v.e-v.s)^(s-v.s));
        int d4 = sgn((v.e-v.s)^(e-v.s));
        if( (d1^d2)== -2 && (d3^d4)== -2)return 2;
        return (d1==0 && sgn((v.s-s)*(v.s-e))<=0) ||
            (d2==0 && sgn((v.e-s)*(v.e-e))<=0) ||
            (d3==0 && sgn((s-v.s)*(s-v.e))<=0) ||
            (d4==0 && sgn((e-v.s)*(e-v.e))<=0);
    }
    // 0平行 1重合 2相交
    int linecrossline(Seg v) const {
        if((*this).parallel(v))
        return v.relation(s)==3;
        return 2;
    }

    void read() { s.read(); e.read(); }
}a[SZ];

vector<Point> keyPoints;

int main() {
    int w = read(),h = read(),n = read();
    for(int i = 1;i <= n;i ++) {
        a[i].read();
    }
    S.read(); T.read();

    keyPoints.push_back(S);
    keyPoints.push_back(T);

    for(int i = 1;i <= n;i ++) {
        keyPoints.push_back(a[i].s);
        keyPoints.push_back(a[i].e);
    }
    keyPoints.push_back(Point(0,0));
    keyPoints.push_back(Point(0,h));
    keyPoints.push_back(Point(w,0));
    keyPoints.push_back(Point(w,h));


   /* Seg ttt = Seg(Point(0,0),Point(4,4));
    Seg sss = Seg(Point(3,2),Point(2,3));
    cout << ttt.segCrossSeg(sss) << " " << sss.segCrossSeg(ttt) << endl;
*/
    graph.init(keyPoints.size());

    for(int i = 0;i < keyPoints.size();i ++) {
        for(int j = i+1;j < keyPoints.size();j ++) {
            Point s = keyPoints[i];
            Point e = keyPoints[j];
            Seg seg = Seg(s,e);
            bool flag = true;
            for(int k = 1;k <= n;k ++) {
                int state = seg.segCrossSeg(a[k]);
                if(state == 2) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                double d = (s-e).len();
                graph.addEdge(i,j,d);
                graph.addEdge(j,i,d);
              /*  printf("%d ",i); s.print();
                printf("%d ",j); e.print();
                printf("%.6f\n",d);*/
            }
        }
    }
    printf("%.4f\n",graph.dij(1,0));
}
/*
int linecrossline(Line v){
    if((*this).parallel(v))
    return v.relation(s)==3;
    return 2;
}
*/
