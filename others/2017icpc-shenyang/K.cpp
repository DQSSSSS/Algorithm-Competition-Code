#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1048600;
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

int a[23333];

int main() {
    int T = read();
    while(T --) {
        int n = read();
        int ans = 0;
        for(int i = 1;i <= n;i ++) {
        	a[i] = read();
    		if(i > 1) ans += a[i] - a[i - 1] - 1;
    	}
    	int x = a[2] - a[1] - 1;
    	int y = a[n] - a[n - 1] - 1;
        ans -= min(x,y);
        printf("%d\n",ans);
    }
    return 0;
}
