#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e5 + 10;

struct point {
	double x,y;
	void read() { scanf("%lf%lf",&x,&y); }
	point operator -(const point &o) const { return (point){x-o.x,y-o.y}; }
};

double Cross(point a,point b) {
	return a.x * b.y - a.y * b.x;
}

int n;

struct line {
	point a,b;
	point crosspoint(line v){
        double a1 = Cross((v.e - v.s),(s - v.s));
        double a2 = Cross((v.e - v.s),(e - v.s));
        return (point){(s.x*a2 - e.x*a1)/(a2 - a1),(s.y*a2 - e.y*a1)/(a2 - a1)};
    }
}a[SZ];

int main() {
	int T;
	scanf("%d",&T);
	while(T --) {
		scanf("%d",&n);
		for(int i = 1;i <= n;i ++) {
			a[i].a.read(); a[i].b.read();		
		}
		for(int i = 1;i <= n;i ++) {
			for(int j = i + 1;j <= n;j ++) {
				
			}
		}
	}
	return 0;
}

