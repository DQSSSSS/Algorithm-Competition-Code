#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1100010;
const int INF = 1e9 + 10;
const int mod = 7340033;
const LD eps = 1e-8;
const LD PI = acos(-1);

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

pii a[SZ],b[SZ];

int main() {
	int n = read();
	for(int i = 1;i <= n;i ++) a[i].first = read(),a[i].second = read();
	for(int i = 1;i <= n;i ++) b[i].first = read(),b[i].second = read();
	sort(a + 1,a + 1 + n);
	sort(b + 1,b + 1 + n);
	printf("%lld %lld\n",a[1].first + b[n].first,a[1].second + b[n].second);
	return 0;
}

