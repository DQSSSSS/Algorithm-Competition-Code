#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
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

int sgn(double x) {
    return x<eps?-1:x>eps;
}

struct Point {
    double x,y;
    Point(double _x=0,double _y=0) :x(_x),y(_y) {}
    Point operator -(Point o) { return Point(x-o.x,y-o.y); }
    double operator *(Point o) { return x*o.x+y*o.y; }
    double operator ^(Point o) { return x*o.y-y*o.x; }
    double dis(Point o) {
        return sqrt((x-o.x)*(x-o.x)+(y-o.y)*(y-o.y));
    }
};

struct Line {
    Point s,e;
    double length() {
        return s.dis(e);
    }
    double disptl(Point p) {
        return fabs((p-s)^(e-s))/length();
    }
    double dispts(Point p) {
        if(sgn((p-s)*(e-s))<0 || sgn((p-e)*(s-e)) < 0) {
            return min(p.dis(s),p.dis(e));
        }
        return disptl(p);
    }
    double dissts(Line o) {
        return min(dispts(o.s),dispts(o.e));
    }
}a[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read();
        for(int i = 1;i <= n;i ++) {
            a[i].s.x = read();
            a[i].s.y = read();
            a[i].e.x = read();
            a[i].e.y = read();
        }
        double ans = 1e18;
        for(int i = 1;i <= n;i ++) {
            for(int j = i + 1;j <= n;j ++){
                ans = min(ans,a[i].dissts(a[j]));
            }
        }
        printf("%.12f\n",ans);
    }
}

