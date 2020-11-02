#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 4e5 + 10;
const int INF = 1e9 + 10;
const LL mod = 1e9 + 7;
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

struct Point {
    int x,y;
    Point(int _x,int _y) :x(_x),y(_y) { }
    Point() {}
    LL operator ^(Point o) { return 1ll*x*o.y-1ll*y*o.x; }
    LL operator *(Point o) { return 1ll*x*o.x+1ll*y*o.y; }
    Point operator -(Point o) { return Point(x-o.x,y-o.y); }
    Point operator +(Point o) { return Point(x+o.x,y+o.y); }
    void Read() { x=read(); y=read(); }
    LL len2() { return 1ll*x*x+1ll*y*y; }
};

int Graham(Point a[],int n) {
    static Point tmp[SZ];
    for(int i = 1;i <= n;i ++) tmp[i] = a[i];
    for(int i = 2;i <= n;i ++)
        if(tmp[i].x < tmp[1].x || (tmp[i].x == tmp[1].x && tmp[i].y < tmp[1].y))
            swap(tmp[i],tmp[1]);
    Point s = tmp[1];
    auto cmp = [&](Point a,Point b) {
        LL t = (a-s)^(b-s);
        return t ? t > 0 : (a-s).len2() < (b-s).len2();
    };
    sort(tmp+2,tmp+1+n,cmp);
    int top = 1;
    for(int i = 2;i <= n;i ++) {
        while(top>1 && ((tmp[top]-tmp[top-1])^(tmp[i]-tmp[top-1])) <= 0) top --;
        tmp[++ top] = tmp[i];
    }
    for(int i = 1;i <= top;i ++) a[i] = tmp[i];
    return top;
}

///a,b内是点集，返回c点集. c[1]是左下角的点
int MinkowskiSum(Point a[],int n,Point b[],int m,Point p[]) {
    static Point v1[SZ],v2[SZ];
    n = Graham(a,n); m = Graham(b,m);
    for(int i = 1;i < n;i ++) v1[i]=a[i+1]-a[i]; v1[n]=a[1]-a[n];
    for(int i = 1;i < m;i ++) v2[i]=b[i+1]-b[i]; v2[m]=b[1]-b[m];
    p[1] = a[1] + b[1];
    int tot = 1,l1 = 1,l2 = 1;
    while(l1 <= n || l2 <= m) {
        tot ++;
        if(l1<=n && (l2>m || (v1[l1]^v2[l2]) >= 0))
            p[tot] = p[tot-1] + v1[l1 ++];
        else
            p[tot] = p[tot-1] + v2[l2 ++];
    }
    while(tot > 1 && ((p[tot]-p[tot-1])^(p[1]-p[tot-1])) <= 0) tot --;
    return tot;
}

bool isInPolygon(Point x,Point p[],int n) {
    Point vx = x - p[1];
    if( (vx^(p[n]-p[1]))<0 || (vx^(p[2]-p[1]))>0 ) return 0;
    Point s = p[1];
    auto cmp = [&](Point a,Point b) {
        LL t = (a-s)^(b-s);
        return t ? t > 0 : (a-s).len2() < (b-s).len2();
    };
    int px = lower_bound(p+2,p+n+1,x,cmp)-p-1;
    return ((x-p[px])^(p[px%n+1]-p[px])) <= 0;
}

Point a[SZ],b[SZ],c[SZ];

int main() {
    int n = read(),m = read(),q = read();
    for(int i = 1;i <= n;i ++) a[i].Read();
    for(int i = 1;i <= m;i ++) b[i].Read(),b[i].x *= -1,b[i].y *= -1;
    int tot = MinkowskiSum(a,n,b,m,c);
    while(q --) {
        Point pp; pp.Read();
        printf("%d\n",isInPolygon(pp,c,tot));
    }
}

/**
4 4 3
0 0
1 0
0 1
1 1
-1 0
0 3
0 2
0 -1
0 0
2 3
0 -1

5
(-4728920,-20310419)
(7667584,-28726709)
(11417244,-21375059)
(12981947,3232993)
(6407435,3293303)
4
(-11250465,455741)
(212338,-27421583)
(8617310,-23838234)
(9897535,-1003568)
9
(-15979385,-19854678)
(-4516582,-47732002)
(7879922,-56148292)
(16284894,-52564943)
(20034554,-45213293)
(21599257,-20605241)
(22879482,2229425)
(1731482,3688734)
(-4843030,3749044)


5
(-4728920,-20310419)
(7667584,-28726709)
(11417244,-21375059)
(12981947,3232993)
(6407435,3293303)
4
(-11250465,455741)
(212338,-27421583)
(8617310,-23838234)
(9897535,-1003568)
*/
