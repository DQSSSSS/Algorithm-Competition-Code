#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 500010;
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

double sinh(double x) { return (exp(x) - exp(-x)) / 2; }
double cosh(double x) { return (exp(x) + exp(-x)) / 2; }

int main() {
	int d,s;
	scanf("%d%d",&d,&s);
	double l = 0,r = 100000;
	for(int i = 1;i <= 300;i ++) {
		double mid = (l + r) / 2;
		double L = mid + s;
		double R = mid * cosh(d/(2*mid));
		cout << L << " " << mid << " " << R << endl;
		if(L <= R) l = mid;
		else r = mid;
	}
	printf("%.10f %.10f\n",l,r);
	printf("%.10f %.10f\n",r+s,r*cosh(d/(2*r)));
	double ans = 2 * r + sinh(d/(2*r));
	printf("%.10f",ans);
	return 0;
}
