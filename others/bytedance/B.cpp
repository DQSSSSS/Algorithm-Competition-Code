#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-8;
const double PI = acos(-1);

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int bits[SZ];
int n,a[SZ],p[SZ];
vector<pii> g[2];
void add(int pos,int d) {
	for(int i = pos;i <= n;i += i & -i) bits[i] += d;
}

int ask(int pos) {
	int ans = 0;
	for(int i = pos;i > 0;i -= i & -i) ans += bits[i];
	return ans;
}

int main() {
	int T = read();
	while(T --) {
		n = read();
		for(int i = 1;i <= n;i ++) a[i] = read(),p[a[i]] = i,bits[i] = 0;
		g[0].clear();
		g[1].clear();
		for(int i = 1,f = 0;i < n;i ++,f ^= 1) {
			int l,r,now = p[i];
			l = min(p[i],p[i + 1]);
			r = max(p[i],p[i + 1]);
			g[f].push_back(make_pair(l,r));
		}
		bool flag = 0;
		for(int i = 0;i < 2;i ++) {
			sort(g[i].begin(),g[i].end());
			for(int j = 1;j <= n;j ++) bits[j] = 0;
			int ff = 0;
			//for(int j = 0;j < g[i].size();j ++) cout << g[i][j].first << " " << g[i][j].second << endl;
			//puts("");
			for(int j = 0;j < g[i].size();j ++) {
				int l = g[i][j].first,r = g[i][j].second;
				int sum = ask(r) - ask(l - 1);
				if(sum) {
					ff = 1; break;
				}
				add(r,1);
			}
			if(ff == 1) {flag = 1; break; }
		}
		if(flag) puts("No");
		else puts("Yes");
	}
	return 0;
}
