#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 4000010;
const int INF = 1e9 + 10;
const int mod = 10007;
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

int n;
struct haha { LD x,y; }a[SZ];

bool check(LD r) {
	LD x = 1e18,y = r;
	for(int i = 1;i <= n;i ++) {
		LD h = abs(a[i].y - r);
		LD delta = sqrt(r*r-h*h);
		x = min(x,a[i].x + delta);
	}

	for(int i = 1;i <= n;i ++) {
		LD d = sqrt((a[i].x-x)*(a[i].x-x)+(a[i].y-y)*(a[i].y-y));
		if(d > r + eps) return false;
	}
	return true;
}

int main() {
	n = read();
	bool allz = 1,allf = 1;
	for(int i = 1;i <= n;i ++) {
		a[i].x = read(),a[i].y = read();
		if(a[i].y < 0) allz = 0;
		if(a[i].y > 0) allf = 0;
		a[i].y = fabs(a[i].y);
	}
	if(allz == 0 && allf == 0) { puts("-1"); return 0; }
	LD l = 0,r = 1e15;
	for(int i = 1;i <= 100;i ++) {
		LD mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid;
	}
	printf("%.10f\n",(double)r);
	return 0;
}
