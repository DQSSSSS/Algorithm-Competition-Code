#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
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

double a[SZ],f1[SZ],f2[SZ],f3[SZ];

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) scanf("%lf",&a[i]);
	double ans = 0;
	for(int i = 1;i <= n;i ++) {
        double p = a[i];
        f1[i] = p * (f1[i - 1] + 1);
        f2[i] = p * (f2[i - 1] + 2 * f1[i - 1] + 1);
        f3[i] = p * (3 * f2[i - 1] + 3 * f1[i - 1] + 1);
        ans += f3[i];
	}
	printf("%.1f\n",ans);
    return 0;
}
