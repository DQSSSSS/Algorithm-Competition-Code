#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
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

LL a[SZ],b[SZ];

int main() {
    int n = read();
    LL maxn = 0;
    LL minn = INF;
    for(int i = 1;i <= n;i ++) {
    	a[i] = a[i + n] = read();
		maxn = max(maxn,a[i]);
		minn = min(minn,a[i]);
	}
    if(maxn == 0) {
		puts("YES");
        for(int i = 1;i <= n;i ++) printf("1 ");
        return 0;
    }
    if(minn == maxn) {
		puts("NO");
		return 0;
    }
    int id = -1;
    for(int i = n;i <= 2 * n - 1;i ++)
    	if(a[i] == maxn && a[i - 1] < a[i]) { id = i; break; }
    int l = id - n + 1,r = id;
    b[r] = a[r]; b[r - 1] = a[r] * 2 + a[r - 1];
    for(int i = r - 2;i >= l;i --) {
        b[i] = b[i + 1] + a[i];
    }
    for(int i = l;i <= r;i ++) b[(i - 1) % n + 1] = b[i];
	puts("YES");
	for(int i = 1;i <= n;i ++) printf("%lld ",b[i]);
    return 0;
}
