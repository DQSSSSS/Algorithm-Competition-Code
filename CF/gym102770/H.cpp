#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
typedef pair<double, double> pdd;
const int SZ = 2000100;
const double INF = 1e10 + 10;
const int mod = 998244353;
const LD eps = 1e-6;

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
    if(fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}

struct Point {
    double x, y;

    Point(double x=0, double y=0):x(x),y(y) {  }
    double operator ^(Point o) { return x*o.y-y*o.x; }
    double operator *(Point o) { return x*o.x+y*o.y; }
    Point operator -(Point o) { return Point(x-o.x,y-o.y); }
    Point operator +(Point o) { return Point(x+o.x,y+o.y); }
    void read() {
        x = ::read();
        y = ::read();
    }
    double len() {
        return sqrt(x*x+y*y);
    }
}stars[SZ];

double askDist(Point a,Point b) {
    double x = a.x-b.x;
    double y = a.y-b.y;
    return sqrt(x*x+y*y);
}

struct Segment {
    Point a,b;

    bool contains(Point o) {
        Point s = o - a;
        Point t = b - a;
        if(sgn(s * t) < 0) return false;
        s = o - b;
        t = a - b;
        if(sgn(s * t) < 0) return false;
        return true;
    }
    void read() {
        a.read();
        b.read();
    }
}clouds[SZ];


pdd getP(Point a,Point b, int loc) {
    if(sgn(a.y-b.y) == 0) {
        if(a.x < b.x) return {-INF,1};
        return {INF,1};
    }
    double x1 = a.x, y1 = a.y;
    double x2 = b.x, y2 = b.y;
    double x = x1 - (x2-x1)/(y2-y1) * y1;
    int f = -1;
    Point c = Point(x, 0);
    if(sgn((c-a)*(b-a)) < 0) {
        f = 1;
    }
    return {x,f};
}

pdd getSeg(int si,int ci) {
    int loc = sgn((clouds[ci].b - clouds[ci].a) ^
        (stars[si] - clouds[ci].a));
   // printf("loc: %d\n",loc);
    if( loc == 0 ) {
        if(clouds[ci].contains(stars[si]))
            return {-INF,INF};
        return {INF,INF};
    }
    pdd p1 = getP(stars[si], clouds[ci].a, 0);
    pdd p2 = getP(stars[si], clouds[ci].b, 1);
    if(p1.second > 0 && p2.second > 0) {
        return {INF,INF};
    } else if(p1.second < 0 && p2.second < 0){
        double x1 = p1.first;
        double x2 = p2.first;
        if(x1 > x2) swap(x1,x2);
        return {x1,x2};
    } else {
        Point a = clouds[ci].a;
        Point b = clouds[ci].b;
        Point p = stars[si];
        double x = p1.second < 0 ? p1.first : p2.first;
        if(p1.second > 0) swap(p1,p2);
        if(p1.first < p2.first) return {-INF,p1.first};
        return {p1.first,INF};
    }
}


int main() {
    int T = read();
    while(T --) {
        int n = read(),m = read();
        for(int i = 1;i <= n;i ++) {
            stars[i].read();
        }
        for(int i = 1;i <= m;i ++) {
            clouds[i].read();
            if(clouds[i].a.x > clouds[i].b.x)
                swap(clouds[i].a, clouds[i].b);
        }

        vector<pdd> vec;
        for(int i = 1;i <= n;i ++) {
            vector<pdd> a;
            for(int j = 1;j <= m;j ++) {
                pdd p = getSeg(i,j);
            //    printf("%d %d: %.10f,%.10f\n",i,j,p.first,p.second);
                a.push_back(p);
            }
            sort(a.begin(),a.end());
            double l = a[0].first,r = a[0].second;
            for(int j = 0;j < a.size();j ++) {
                r = max(r,a[j].second);
                if(j+1 == a.size() || a[j+1].first > r) {
                    vec.push_back({l,r});
                    if(j+1 < a.size()) {
                        l = a[j+1].first;
                        r = a[j+1].second;
                    }
                }
            }
          /*  printf("%d:\n",i);
            for(auto p : a) {
                printf("[%.10f,%.10f]\n",p.first,p.second);
            }*/
        }

        vector<double> lsh;
        lsh.push_back(-INF);
        lsh.push_back(INF);
        for(auto p : vec) {
            lsh.push_back(p.first);
            lsh.push_back(p.second);
        }
        sort(lsh.begin(),lsh.end());
        lsh.resize(unique(lsh.begin(), lsh.end()) - lsh.begin());
        vector<int> a; a.resize(lsh.size());
        for(auto p : vec) {
            int l = lower_bound(lsh.begin(), lsh.end(), p.first-eps) - lsh.begin();
            int r = lower_bound(lsh.begin(), lsh.end(), p.second-eps) - lsh.begin();
            a[l] ++;
            a[r] --;
     //       printf("[%d,%d]\n",l,r);
        }
        double ans = 0;
        int sum = 0;
      //  for(int i = 0;i < a.size();i ++) printf("%d ",a[i]); puts("");
        for(int i = 0;i + 1 < a.size();i ++) {
            sum += a[i];
            if(sum == n) {
                ans += lsh[i+1]-lsh[i];
            }
        }
        if(ans > 1e9) puts("-1");
        else printf("%.10f\n",ans);
      //  puts("------------------");
    }
    return 0;
}
/*
8
1 2
0 3
-2 1 -1 1
2 1 1 1

1 2
0 3
-2 1 -1 1
1 2 2 1

2 2
10000 100
-10000 100
-10000 50 -3000 50
10000 50 3000 50

2 2
0 3
-1 10
3 2 0 1
0 1 -1 10

1 1
0 2
1 1 3 2

1 1
0 10000
-10000 9999 10000 9999

1 1
0 10000
-9999 9999 9999 9999

1 1
0 10000
-10000 1 9999 2



233

1 1
0 1
0 2
0 3

1 1
0 3
-1 4 1 4

1 4
0 3
-1 4 1 4
1 4 1 3
1 2 -1 2
-1 3 -1 4

1 4
0 3
-1 4 1 4
1 4 1 2
1 2 -1 2
-1 2 -1 4

1 3
0 5
-1 4 2 4
-1 4 3 3
-2 1 2 4

2 1
0 4
0 4
-1 4 1 4

1 4
0 4
-1 5 1 5
1 3 1 2
1 2 -1 2
-1 2 -1 3

1 4
0 6
-1 1 4 6
4 4 -1 9
1 9 -4 4
-4 6 1 1

2 1
0 5
9 5
5 4 10 9


1 1
0 5
0 2 3 5

0
0
6
-1
15
-1
-1


1
3 4
6 5
9 1
10 5
1 8 3 7
6 4 6 5
9 9 6 8
2 10 8 7


*/
