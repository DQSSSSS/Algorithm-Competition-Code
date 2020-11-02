#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
const int INF = 1e9 + 10;
const int mod = 19901013;
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
        LL a = read(),b = read();
        double tmp = 2.0 * b + (acos(-1.0) * a);
        LL ans = (long long)(tmp * 1000000);
        printf("%.6f\n",ans / 1000000.0);
    }
    return 0;
}
