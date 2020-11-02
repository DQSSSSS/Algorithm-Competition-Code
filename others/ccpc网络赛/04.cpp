#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
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

int main() {
    int T = read();
    while(T --) {
		LL n = read(),a = read();
        if(n > 2 || n == 0) { printf("-1 -1\n"); continue; }
        if(n == 1) { printf("%lld %lld\n",1ll,a + 1); continue; }
        if(a == 4) { printf("3 5\n"); continue; }
        if(a % 2 == 0) {
        	LL n = a / 2;
            LL b = n * n - 1;
            LL c = n * n + 1;
            printf("%lld %lld\n",b,c);
			assert(a * a + b * b == c * c);
        }
        else {
        	LL n = (a - 1) / 2;
            if(n == -1) { printf("-1 -1\n"); }
			else {
				LL b = 2 * n * (n + 1);
				LL c = 2 * n * n + 2 * n + 1;
				printf("%lld %lld\n",b,c);
        		assert(a * a + b * b == c * c);
        	}
        }
    }
    return 0;
}
