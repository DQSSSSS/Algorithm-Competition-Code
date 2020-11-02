#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;

LL read()
{
    LL n = 0;
    char a = getchar();
    int flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}


int main() {
	int T = read();
	while(T --) {
		int n = read();
		LL ans = 0;
		for(int i = 1;i <= n;i ++) {
			int a = read(),b = read();
			ans += 1ll * a * b;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
