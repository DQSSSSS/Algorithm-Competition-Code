#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 200010;
const LL INF = 1e18 + 10;
const int mod = 1e9 + 7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

double f[1010][1010];
bool g[1010][1010];

double P(int n,int m) {
    if(g[n][m]) return f[n][m];
    if(n == 0) return 1.0/(m+1);
    if(m == 0) return 1;
    g[n][m] = 1;
    double A = 1 - P(m,n-1);
    double B = 1;
    double C = 1.0/(m+1) + m/(m+1.0)*(1-P(m-1,n));
    double D = m/(m+1.0)*(1-P(m-1,n));
    double p =  (D-C) / (A-C-B+D);
    return f[n][m] = p * A + (1-p) * C;
}

int main() {
    int n = read(),m = read();
    double ans = P(n,m);
    printf("%.10f %.10f\n",ans,1-ans);
}
