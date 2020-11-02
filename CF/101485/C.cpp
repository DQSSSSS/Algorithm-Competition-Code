#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
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

LL sgn(LL x) {
    if(x<0) return -1;
    if(x == 0) return 0;
    return 1;
}

struct Point {
    LL x,y;
    Point() {}
    Point(int _x,int _y) { x = _x; y = _y; }
    bool operator ==(Point o) { return o.x == x && o.y == y; }
    Point operator -(Point o) { return Point(x-o.x,y-o.y); }
    LL operator ^(Point o) { return x*o.y-y*o.x; }
    LL operator *(Point o) { return x*o.x+y*o.y; }
}P[SZ];

struct Line {
    Point s,e;
    Line() {}
    Line(Point _x,Point _y) { s = _x; e = _y; }
    int segcrossseg(Line v){
        int d1 = sgn((e-s)^(v.s-s));
        int d2 = sgn((e-s)^(v.e-s));
        int d3 = sgn((v.e-v.s)^(s-v.s));
        int d4 = sgn((v.e-v.s)^(e-v.s));
        if( (d1^d2)== -2 && (d3^d4)== -2 )return 2;
        return (d1==0 && sgn((v.s-s)*(v.s-e))<=0) ||
            (d2==0 && sgn((v.e-s)*(v.e-e))<=0) ||
            (d3==0 && sgn((s-v.s)*(s-v.e))<=0) ||
            (d4==0 && sgn((e-v.s)*(e-v.e))<=0);
    }
};

struct haha {
    int id,x,y;
}a[SZ];

vector<int> g[SZ];

int c[SZ];

bool dfs(int u,int col) {
    c[u] = col;
    for(int v : g[u]) {
        if(c[v] == -1) {
            if(!dfs(v,col^1)) return false;
        }
        else {
            if(c[u] == c[v]) return false;
        }
    }
    return true;
}

int main() {
    int n = read(),p = read();
    for(int i = 1;i <= n;i ++) {
        P[i].x = read();
        P[i].y = read();
    }
    for(int i = 1;i <= p;i ++) {
        a[i].id = read();
        a[i].x = read();
        a[i].y = read();
    }
    for(int i = 1;i <= p;i ++) {
        for(int j = i+1;j <= p;j ++) {
            if(a[i].id != a[j].id) {
                Line l1 = Line(P[a[i].id],Point(a[i].x,a[i].y));
                Line l2 = Line(P[a[j].id],Point(a[j].x,a[j].y));
                if(l1.segcrossseg(l2)) {
                    //g[a[i].id].push_back(a[j].id);
                    //g[a[j].id].push_back(a[i].id);
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
    }
    for(int i = 1;i <= p;i ++) c[i] = -1;
    for(int i = 1;i <= p;i ++) {
        if(c[i] == -1) {
            if(!dfs(i,0)) return puts("impossible"),0;
        }
    }
    puts("possible");
}
