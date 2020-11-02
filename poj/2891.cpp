#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 10000010;
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

LL exgcd(LL a,LL b,LL &x,LL &y) {
	if(b == 0) {
        x = 1; y = 0;
        return a;
	}
    LL d = exgcd(b,a%b,x,y);
    LL t = x;
    x = y; y = t - a / b * y;
	return d;
}

int n;
LL m[SZ],a[SZ];

LL work() {
    LL M = m[1],A = a[1],x,y;
    for(int i = 2;i <= n;i ++) {
    	LL d = exgcd(M,m[i],x,y);
        if((a[i] - A) % d) return -1;
        x *= (a[i] - A) / d;
        LL t = m[i] / d; x = (x % t + t) % t;
        A = M * x + A; M = M / d * m[i]; A %= M;
    }
	return (A += M) %= M;
}

int main() {
	while(~scanf("%d",&n)) {
		for(int i = 1;i <= n;i ++)
			m[i] = read(),a[i] = read();
		printf("%lld\n",work());
	}
    return 0;
}
