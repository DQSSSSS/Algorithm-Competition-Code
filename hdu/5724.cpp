#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 2000010;
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

int sg[SZ];

void print(int x) {
	for(int i = 20;i >= 0;i --)
		cout << (x >> i & 1);
}

int dfs(int x) {
	if(sg[x] != -1) return sg[x];
	bool vis[22] = {0};
    for(int i = 0,pos = -1;i < 20;i ++) {
		if(x & (1 << i)) {
			if(pos != -1)
				vis[dfs(x ^ (1 << i) ^ (1 << pos))] = 1;
		}
		else {
			pos = i;
		}
    }
	for(int i = 0;;i ++)
		if(!vis[i])
			return sg[x] = i;
}

int main(){
    int T = read();
    memset(sg,-1,sizeof(sg));
    for(int i = 0;i <= 20;i ++) sg[(1 << i) - 1] = 0;
    for(int i = 0;i <= (1 << 20) - 1;i ++)
    	dfs(i);
    while(T --) {
		int n = read();
		int ans = 0;
		for(int i = 1;i <= n;i ++) {
			int k = read(),x = 0;
			while(k --) {
				int d = read(); d = 20 - d;
                x |= 1 << d;
			}
			ans ^= sg[x];
		}
		if(ans) puts("YES");
		else puts("NO");
    }
    return 0;
}
