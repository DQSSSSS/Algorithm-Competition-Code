#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 300010;
const LL INF = 1e18 + 10;
const int mod = 10007;
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

bitset<1510> g[1510];

int n,k;

bool gauss() {
	int now = 0;
	for(int i = 1;i <= k;i ++) {
		int j = now + 1;
		while(j <= n && !g[j][i]) j ++;
		if(j > n) continue;
		now ++;
		swap(g[j],g[now]);
		for(int j = 1;j <= n;j ++)
			if(j != now && g[j][i])
				g[j] ^= g[now];
	}
	for(int i = 1;i <= n;i ++)
		if(g[i].count() == 1 && g[i][0]) return true;
	return false;
}

int main() {
	n = read(),k = read();
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j <= k;j ++) {
			int x = read();
			if(x % 2) g[i].set(j);
		}
		g[i].set(0);
	}
	if(gauss()) puts("No");
	else puts("Yes");
/*	for(int i = 1;i <= n;i ++,puts(""))
		for(int j = 0;j <= k;j ++)
			cout << g[i][j] << " ";*/
	return 0;
}
