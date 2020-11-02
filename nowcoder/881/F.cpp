#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
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

struct point {
    double x,y;
    int read() {
        return scanf("%lf%lf",&x,&y);
    }
}A,B,C;

point get(point a,point b,point c) {
    double x1 = a.x,x2 = b.x,x3 = c.x;
    double y1 = a.y,y2 = b.y,y3 = c.y;
    double x7,y7;
    x7 = -(x1*x2*y1 - x1*x3*y1 - x1*x2*y2 + x2*x3*y2 + y1*y1*y2 -
           y1*y2*y2 + x1*x3*y3 - x2*x3*y3 - y1*y1*y3 + y2*y2*y3 +
           y1*y3*y3 - y2*y3*y3) /
           (-x2*y1 + x3*y1 + x1*y2 - x3*y2 - x1*y3 + x2*y3);
    y7 = -(x1*x1*x2 - x1*x2*x2 - x1*x1*x3 + x2*x2*x3 + x1*x3*x3 -
           x2*x3*x3 + x1*y1*y2 - x2*y1*y2 - x1*y1*y3 + x3*y1*y3 +
           x2*y2*y3 - x3*y2*y3) /
           (x2*y1 - x3*y1 - x1*y2 + x3*y2 + x1*y3 - x2*y3);
    return (point){x7,y7};
}

double dis(point a,point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx+dy*dy);
}

int main() {
    while(~A.read()) {
        B.read(),C.read();
        point o = get(A,B,C);

    }
}
