#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-8;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int randint() {
	return rand() << 16 |rand();
}

int randlr(int l,int r) {
	return randint() % (r - l + 1) + l;
}

struct point {
	double x,y;
	double dist(point o) { return sqrt((x - o.x) * (x - o.x) + (y - o.y) * (y - o.y)); }
	point operator -(point o) { return (point){x-o.x,y-o.y}; }
	double operator ^(point o) { return x * o.y - y * o.x; }
	double operator *(point o) { return x * o.x + y * o.y; }
	void get() { x = randlr(1,1<<16)-1; y = randlr(1,1<<16)-1; }
};

double sgn(double x) { return x; }

struct haha {
	point a,b;
	int t;
	double length() { return a.dist(b); }
	double dispointtoline(point p){
        return fabs((p - a)^(b - a))/length();
    }

	double dist(point p){
        if(sgn((p - a)*(b - a))<0 || sgn((p - b)*(a - b))<0)
        return min(p.dist(a),p.dist(b));
        return dispointtoline(p);
    }
}l[SZ];

int n = 10000,q = 1e5;

double a[SZ];

int main() {
	freopen("g.txt","w",stdout);
	srand(time(0));
	
	for(int i = 1;i <= n;i ++){	
		l[i].a.get();
		l[i].b.get();
		a[i] = l[i].length();
	}
	while(q --) {
		point o; o.get();
		double mind = INF;
		for(int i = 1;i <= n;i ++) {
			mind = min(mind,l[i].dist(o));
		}
		for(int i = 1;i <= n;i ++)
			if(fabs(l[i].dist(o) - mind) < eps) l[i].t ++;
		
	}
	for(int i = 1;i <= n;i ++) {
		cout << l[i].length() << " " << l[i].t<< endl;
	}
}

