#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-12;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

struct haha {
	double a,b,c;
    haha operator +(const haha &o) const {
        return (haha) {a + o.a,b + o.b,c + o.c};
    }
    haha operator *(const double x) const {
        return (haha) {a * x,b * x,c * x};
    }
}f[110][110][110];

haha dfs(int a,int b,int c) {
    if(a < 0 || b < 0 || c < 0) return (haha){0,0,0};
    haha &now = f[a][b][c];
    if(now.a + now.b + now.c >= eps) return now;
    if(a == 0 && b == 0) { now.c = 1; return now; }
    if(a == 0 && c == 0) { now.b = 1; return now; }
    if(c == 0 && b == 0) { now.a = 1; return now; }
    int n = a + b + c;
	double pa = 1.0 * a / n,pb = 1.0 * b / n,pc = 1.0 * c / n;
    double ab = pa * pb,ac = pa * pc,bc = pb * pc,tot = ab + ac + bc;
    now = now + dfs(a - 1,b,c) * (ac / tot);
    now = now + dfs(a,b - 1,c) * (ab / tot);
    now = now + dfs(a,b,c - 1) * (bc / tot);
    return now;
}

int main() {
	int a = read(),b = read(),c = read();
	dfs(a,b,c);
    printf("%.10f %.10f %.10f\n",f[a][b][c].a,f[a][b][c].b,f[a][b][c].c);
	return 0;
}
