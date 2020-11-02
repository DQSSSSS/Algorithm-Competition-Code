#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 4e5 + 10;
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

int num[SZ],t[SZ];
const double PI = acos(-1);

int main() {
    double n,r;
    scanf("%lf%lf",&n,&r);
    double a = PI / n;
    printf("%.10f\n",r * sin(a) / (1 - sin(a)));
}

